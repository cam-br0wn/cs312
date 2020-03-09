#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define myqDebug() qDebug() << fixed << qSetRealNumberPrecision( 14 )

int adsrState;

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
        }
        // Decay phase
        else if ( adsrState == kDcyState )
        {
            // decrement envAmp by decay
            // if envAmp < sustain level (lvlS)
            //      set envAmp to lvlS
            //      and set adsrState to kSusState
        }
        // Sustain phase
        else if ( adsrState == kSusState )
        {
            // set envAmp to lvlS
            //      check for isKeyUp
            //      if true set adsrState to kRlsState
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
    /*
        calculate sustain level from slider value
        lvlS = ui->verticalSlider_SL->value() * .01;

        calculate millisecond A D R times from slider value * 10
        msA = ui->verticalSlider_A->value() * 10;

        If you know ms duration there are 44100/1000 samples per millisecond
        calcualate attackInc = 1.0/(msA * kSamplesPerMs)


        calcualate decayInc = (1.0 - lvlS)/(msD * kSamplesPerMs)
        calcualate releasekInc = (lvlS - 0)/(msR * kSamplesPerMs)

        calculate start/end values for A D in samples
        sampStartA = 0;
        sampEndA =  msA * kSamplesPerMs
        sampStartD = end A + 1
        sampEndD = start D + number samples in D
        sampStartS = end D + 1
        NOTE: sampEndS is calculated elsewhere
            for plot it's totalPlotSamples - (A length + D length + R length)
            for sine callback its when key button is released.
        sampLenR = msR * kSamplesPerMs

*/
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
            // if samp < lvlS
            // set samp = lvlS
            // and set adsrState to kDcyState
            // venv.push_back( samp );
        }
        // Sustain phase
        else if ( adsrState == kSusState )
        {
            // while Slength > 0
            // Slength--
            // venv.push_back( samp );
            // and set adsrState to kRlsState
        }
        // Release
        else if ( adsrState == kRlsState )
        {
            // decrement samp by releaseInc
            // if samp < 0
            // set samp = 0
            // and set adsrState to kDcyState
            // venv.push_back( samp );
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
}

void MainWindow::open_dac_stream()
{
    // You've done this before
    // Copy/paste from previous homework
}

MY_TYPE MainWindow::midi2frequency( const int midiNote )
{
    // implement the formula from week 7.3 web page
    MY_TYPE frq{0}; // avoid compile error
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
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_loC_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Db_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_Db_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_D_pressed()
{
    // Copy/paste/modify examples on web page
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
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_E_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_F_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_F_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Gb_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_Gb_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_G_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_G_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Ab_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_Ab_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_A_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_A_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_Bb_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_Bb_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_B_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_B_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}

void MainWindow::on_toolButton_hiC_pressed()
{
    // Copy/paste/modify examples on web page
}

void MainWindow::on_toolButton_hiC_released()
{
    isKeyUp = true;
    isKeyDown = false;
    stopNote();
}
