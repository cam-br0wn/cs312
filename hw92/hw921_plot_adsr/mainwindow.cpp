#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define myqDebug() qDebug() << fixed << qSetRealNumberPrecision( 14 )

int adsrState;

bool isPlaying = true;


bool isKeyDown{false};
bool isKeyUp{true};
bool isNoteOver{false};

MY_TYPE lvlS{0.25};
MY_TYPE freq{261.63};
MY_TYPE envAmp{1.0};
MY_TYPE sliderVolume{0.5};
int count{0};

int msA{500};
int msD{500};
int msR{500};

int sampStartA{0};
int sampEndA{0};
int sampStartD{0};
int sampEndD{0};
int sampStartS{0};
int sampLenR{0};
int sampStartR{0};
int sampEndR{0};

double attackInc{0};
double decayInc{0};
double releaseInc{0};

std::vector<MY_TYPE> venv;

#define USECALLBACK 0

// Remember to change callback name in open_dac_stream()
int MainWindow::sineADSRCallback( void* outputBuffer, void* /*inputBuffer*/, unsigned int nBufferFrames,
                                  double /*streamTime*/, RtAudioStreamStatus status, void* /*userData*/ )
{
    //    if ( envAmp < 0 )
    //        return 0;

    if ( isNoteOver )
        return callbackReturnValue;

    MY_TYPE* buffer = static_cast<MY_TYPE*>( outputBuffer );
    if ( status )
        std::cout << "Stream underflow detected!" << std::endl;
    static MY_TYPE phz = 0;
    // //phase increment formula
    const MY_TYPE phzinc = k2PIT * freq;
    for ( uint32_t i = 0; i < nBufferFrames; i++ )
    {

        // implement state machine for calculating envAmp for each sample
        // Attack phase
        if ( adsrState == kAtkState )
        {
            // increment envAmp by attackInc
            // if envAmp >= 1.0
            //      set envAmp to 1.0
            //      and set adsrState to kDcyState
            envAmp += attackInc;
            if (envAmp >= 1.0) {
                envAmp = 1.0;
                adsrState = kDcyState;
            }
        }
        // Decay phase
        else if ( adsrState == kDcyState )
        {
            // decrement envAmp by decay
            // if envAmp < sustain level (lvlS)
            //      set envAmp to lvlS
            //      and set adsrState to kSusState
            envAmp -= decayInc;
            if (envAmp < lvlS) {
                envAmp = lvlS;
                adsrState = kSusState;
            }
        }
        // Sustain phase
        else if ( adsrState == kSusState )
        {
            // set envAmp to lvlS
            //      check for isKeyUp
            //      if true set adsrState to kRlsState
            envAmp = lvlS;
            if (isKeyUp) {
                adsrState = kRlsState;
        }

        }
        // Release
        else if ( adsrState == kRlsState )
        {
            // set sampStartR to count
            // set sampEndR to sampStartR + sampLenR
            // decrement envAmp by releaseInc
            // if envAmp < 0
            //      set envAmp = 0
            //      and set isNoteOver to true
            sampStartR = count;
            sampEndR = sampStartR + sampLenR;
            envAmp -= releaseInc;
            if (envAmp < 0) {
                envAmp = 0;
                isNoteOver = true;
            }
        }

        *buffer++ = sliderVolume * envAmp * sin( phz );

        phz += phzinc;
        if ( phz >= k2PI )
            phz -= k2PI;
        ++count;
    }
    rta.frameCounter += nBufferFrames;
    if ( rta.checkCount && ( rta.frameCounter >= rta.nFrames ) )
        return callbackReturnValue;

    QApplication::processEvents();

    // Usefull for debuging
    //    myqDebug() << count << " " << adsrState << " " << isKeyUp;
    return 0;
}

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::MainWindow )
{
    ampSlider = 0.5;
    envAmp = 0;
    MIDIstartNote = 60;

    ui->setupUi( this );
    init_controls();
#if USECALLBACK
    open_dac_stream();
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
#if USECALLBACK
    if ( dac.isStreamOpen() )
        dac.closeStream();
#endif
}

void MainWindow::init_controls()
{

    ui->verticalSlider_A->setValue( 50 );
    ui->verticalSlider_D->setValue( 50 );
    ui->verticalSlider_SL->setValue( static_cast<int>( ( lvlS * 100 ) ) );
    ui->verticalSlider_R->setValue( 50 );

    ui->label_Aval->setNum( 500 );
    ui->label_Dval->setNum( 500 );
    ui->label_SLval->setNum( lvlS );
    ui->label_Rval->setNum( 500 );

    calcADSR_start_end_points();
    plotEnvelope();
}

void MainWindow::calcADSR_start_end_points()
{

   //     calculate sustain level from slider value
        lvlS = ui->verticalSlider_SL->value() * .01;

      //  calculate millisecond A D R times from slider value * 10
        msA = ui->verticalSlider_A->value() * 10;

       // If you know ms duration there are 44100/1000 samples per millisecond
        MY_TYPE attackInc = 1.0/(msA * kSamplesPerMs);

       //  calcualate decayInc = (1.0 - lvlS)/(msD * kSamplesPerMs)
       // calcualate releasekInc = (lvlS - 0)/(msR * kSamplesPerMs)
        MY_TYPE decayInc = (1.0 - lvlS)/(msD * kSamplesPerMs);
        MY_TYPE releasekInc = (lvlS - 0)/(msR * kSamplesPerMs);

       // calculate start/end values for A D in samples
        sampStartA = 0;
        sampEndA =  msA * kSamplesPerMs;
        sampStartD = sampEndA + 1;
      //  sampEndD = start D + number samples in D
        sampStartS = sampEndD + 1;
      //  NOTE: sampEndS is calculated elsewhere
          //  for plot it's totalPlotSamples - (A length + D length + R length)
           // for sine callback its when key button is released.
       sampLenR = msR * kSamplesPerMs;


    // Useful for debugging
    qDebug() << "A start end" << sampStartA << " " << sampEndA;
    qDebug() << "D start end" << sampStartD << " " << sampEndD;
    qDebug() << "S start lvl" << sampStartS << " " << lvlS;
    qDebug() << "R start lvl" << sampLenR;
    // myqDebug() defined at top to display doubles with using scientific notation
    myqDebug() << "attackInc decayInc releaseInc" << attackInc << " " << decayInc << " " << releaseInc;
}

std::vector<MY_TYPE> MainWindow::stuffEnvelopeVector()
{
    calcADSR_start_end_points();

    // Calculate Slength as Slength = kEnvLength - ( sampEndD + sampLenR )
    int Slength = kEnvLength - (sampEndD + sampLenR);


    MY_TYPE samp{0};
    int count{0};

    for ( uint32_t n = 0; n < kEnvLength; n++ )
    {
        // This what I did for attack state
        if ( count <= sampEndA )
        {
            samp += attackInc;
            if ( samp >= 1.0 )
            {
                samp = 1.0;
                adsrState = kDcyState;
            }
            venv.push_back( samp );
        }
        // Decay phase
        else if ( adsrState == kDcyState )
        {
            // decrement samp by decayInc
            samp -= decayInc;
            // if samp < lvlS
            // set samp = lvlS
            // and set adsrState to kDcyState
            // venv.push_back( samp );
            if (samp < lvlS) {
                samp=lvlS;
                adsrState = kDcyState;
                venv.push_back(samp);
            }

        }
        // Sustain phase
        else if ( adsrState == kSusState )
        {
            // while Slength > 0
            // Slength--
            // venv.push_back( samp );
            // and set adsrState to kRlsState
            while (Slength > 0) {
                Slength--;
                venv.push_back(samp);
                adsrState = kRlsState;
            }

        }
        // Release
        else if ( adsrState == kRlsState )
        {
            // decrement samp by releaseInc
            // if samp < 0
            // set samp = 0
            // and set adsrState to kDcyState
            // venv.push_back( samp );
            samp -= releaseInc;
            if (samp < 0) {
                samp = 0;
                adsrState = kDcyState;
                venv.push_back(samp);
            }
        }
        count++;
    }
    return venv;
}

void MainWindow::plotEnvelope()
{
    /*
        clear venv
        call stuffEnvelopeVector()
        create QVector<double> x and QVector<double> y using kEnvLength as size
        for loop to set x and y values from 0 < kEnvSize
            x are loop indices
            y are venv values
        customPlot stuff you've used before
            addGraph
            setData
            x axis setRange
            y axis setRange
            replot
        reset adsrState to kAtkState becuase it was changed in stuffEnvelopeVector()
      */

    venv.clear();
    std::vector<MY_TYPE> envVec = stuffEnvelopeVector();

    QVector<MY_TYPE> x(kEnvLength);
    QVector<MY_TYPE> y(kEnvLength);

    for (int i = 0; i < kEnvLength; i++) {
        x[i] = i;
        y[i] = venv[i];
    }


    // create graph and assign data to it
    ui->customPlot->addGraph();
    ui->customPlot->graph( 0 )->setData( x, y );
    ui->customPlot->xAxis->setRange( 0, kEnvLength - 1 );
    ui->customPlot->yAxis->setRange( 0, 1 );
    ui->customPlot->replot();

    adsrState = kAtkState;
}

void MainWindow::open_dac_stream()
{
       if ( dac.isStreamOpen() )
           return;

       if ( dac.getDeviceCount() < 1 )
       {
           std::cout << "\nNo audio devices found!\n";
           exit( 1 );
       }

       MY_TYPE* data = static_cast<MY_TYPE*>( calloc( rta.channels, sizeof( MY_TYPE ) ) );

       // Let RtAudio print messages to stderr.
       dac.showWarnings( true );

       const bool USE_DEFAULT_OUTPUT{true};
       if ( USE_DEFAULT_OUTPUT )
       { // Set our stream parameters for output only.
           if ( rta.device == 0 )
               rta.device = dac.getDefaultOutputDevice();
       }
       else
       {
           // I used the commented code at the start of open_dac_stream()
           // to find my external audio interface
           // I used the debugger to view dac.GetDeviceInfo() to find the id number
           rta.device = 3;
       }

       oParams.deviceId = rta.device;
       dac.openStream( &oParams, nullptr, FORMAT, rta.fs, &rta.bufferFrames, sineADSRCallback, static_cast<void*>( data ), &options, &errorCallback );


       QApplication::processEvents();

}

MY_TYPE MainWindow::midi2frequency( const int midiNote )
{

    MY_TYPE frq = 440 * pow(2, midiNote-69/12);
    return frq;
}

void MainWindow::playNote( const int note )
{
    if ( dac.isStreamRunning() )
        dac.stopStream();
    adsrState = kAtkState;
    isKeyDown = true;
    isNoteOver = false;
    calcADSR_start_end_points();

    freq = midi2frequency( note );
    plotEnvelope();


#if USECALLBACK
    dac.startStream();
#endif
}

void MainWindow::stopNote()
{
    #if USECALLBACK
            if ( isNoteOver )
                dac.stopStream();
    #endif
}

void MainWindow::on_verticalSlider_A_valueChanged( int value )
{
    msA = value;
    ui->label_Aval->setNum( msA * 10 );
    calcADSR_start_end_points();
    plotEnvelope();
}

void MainWindow::on_verticalSlider_D_valueChanged( int value )
{
    msD = value;
    ui->label_Dval->setNum( msD * 10 );
    calcADSR_start_end_points();
    plotEnvelope();
}

void MainWindow::on_verticalSlider_SL_valueChanged( int value )
{
    lvlS = value;
    ui->label_SLval->setNum( lvlS * .01 );
    calcADSR_start_end_points();
    plotEnvelope();
}

void MainWindow::on_verticalSlider_R_valueChanged( int value )
{
    msR = value;
    ui->label_Rval->setNum( msR * 10 );
    calcADSR_start_end_points();
    plotEnvelope();
}

void MainWindow::on_pushButton_Stop_clicked()
{
#if USECALLBACK
    dac.stopStream();
#endif
}

void MainWindow::on_pushButton_quit_clicked()
{
#if USECALLBACK
    if ( dac.isStreamOpen() )
        dac.closeStream();
#endif
    QApplication::quit();
}

void MainWindow::on_verticalSlider_volume_valueChanged( int value )
{
    sliderVolume = value * .01;
    ui->label_volume->setNum( sliderVolume );
}

void MainWindow::on_comboBox_currentIndexChanged( int index )
{
    MIDIstartNote = index * 12 + 24;
}

void MainWindow::on_toolButton_loC_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote - 12 );
}

void MainWindow::on_toolButton_loC_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Db_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 1 );
}

void MainWindow::on_toolButton_Db_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_D_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 2 );
}

void MainWindow::on_toolButton_D_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Eb_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 3 );
}

void MainWindow::on_toolButton_Eb_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_E_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 4 );
}

void MainWindow::on_toolButton_E_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_F_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 5 );
}

void MainWindow::on_toolButton_F_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Gb_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 6 );
}

void MainWindow::on_toolButton_Gb_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_G_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 7 );
}

void MainWindow::on_toolButton_G_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Ab_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 8 );
}

void MainWindow::on_toolButton_Ab_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_A_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 9 );
}

void MainWindow::on_toolButton_A_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Bb_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 10 );
}

void MainWindow::on_toolButton_Bb_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_B_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 11 );
}

void MainWindow::on_toolButton_B_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_hiC_pressed()
{
    envAmp = 0;
    isKeyDown = true;
    isKeyUp = false;
    count = 0;
    playNote( MIDIstartNote + 12 );
}

void MainWindow::on_toolButton_hiC_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}
