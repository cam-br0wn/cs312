#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef WAVEREADWRITE_H_
#include "wavReadWrite.h"
#endif

#ifndef BANDLIMITEDWAVS_H
#include "bandlimitedwavs.h"
#endif

#include <QDebug>
#include <QMessageBox>
#include <QPalette>

#include <fstream>

int rtCallback( void* outputBuffer, void* /*inputBuffer*/, unsigned int nBufferFrames,
                double /*streamTime*/, RtAudioStreamStatus status, void* /*userData*/ )
{
    MY_TYPE* cb_buffer = static_cast<MY_TYPE*>( outputBuffer );
    if ( status )
        std::cout << "Stream underflow detected!" << std::endl;

    if ( isSine )
        doSineCallback( nBufferFrames, cb_buffer );
    else if ( isSquare )
        doSquareBLCallback( nBufferFrames, cb_buffer );
    else if ( isSawUp )
        doSawUpBLCallback( nBufferFrames, cb_buffer );
    else if ( isSawDown )
        doSawDownBLCallback( nBufferFrames, cb_buffer );
    else if ( isTriangle )
        doTriangleBLCallback( nBufferFrames, cb_buffer );

    rta.frameCounter += nBufferFrames;
    if ( rta.checkCount && ( rta.frameCounter >= rta.nFrames ) )
        return callbackReturnValue;

    return 0;
}

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    init_controls();
    isSine = true;
    ewave = esine;
    updatePlot( esine );
    open_dac_stream();
}

MainWindow::~MainWindow()
{
    delete ui;
    if ( dac.isStreamOpen() )
        dac.closeStream();
}

void MainWindow::init_controls()
{
    ui->horizontalSlider_freq->setValue( static_cast<int>( hSlider_freq ) );
    ui->label_freqValue->setNum( ui->horizontalSlider_freq->value() );
    ui->horizontalSlider_amp->setValue( static_cast<int>( hSlider_ampl * 100 ) );
    ui->label_ampValue->setNum( static_cast<MY_TYPE>( hSlider_ampl ) );

    ui->horizontalSlider_harm->setValue( hSlider_numHarmonics );
    setNyquistWarning( Qt::green );
    setNyquistMaxHarm( hSlider_freq );
    ui->label_ampValue->setNum( static_cast<MY_TYPE>( hSlider_ampl ) );
}

void MainWindow::setNyquistWarning( QColor color )
{
    QPixmap px( 20, 20 );
    px.fill( color );
    ui->toolButton_GreenRed->setIcon( px );
}

void MainWindow::setNyquistMaxHarm( MY_TYPE freq )
{
    if ( ewave == esine )
        return;

    qDebug() << "You need setNyquistWarning() when hSlider_numHarmonics > FS/2 at slider hSlider_freq";
    // Example
    if ( hSlider_numHarmonics < 6 )
        setNyquistWarning( Qt::green );
    else
        setNyquistWarning( Qt::red );
}

void MainWindow::open_dac_stream()
{
    // You could use this to get the rta.device if you have an external USB audio device
    // unsigned int numDev = dac.getDeviceCount();
    // RtAudio::DeviceInfo di;
    // for ( unsigned int i = 0; i < numDev; ++i )
    // {
    //     di = dac.getDeviceInfo( i );
    // }
    // if ( !isPlaying )
    //     return;

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
    dac.openStream( &oParams, nullptr, FORMAT, rta.fs, &rta.bufferFrames, rtCallback, static_cast<void*>( data ), &options, &errorCallback );

    while ( isPlaying )
    {
        QApplication::processEvents();
    }
}

void MainWindow::on_pushButton_play_clicked()
{
    vsamps.clear();
    // reserve 5 minutes to avoid memory allocation when filling buffer
    // helps eliminate "popcorn" noise when moving frequency slider
    vsamps.reserve( 60 * 5 * FS );
    isPlaying = true;
    dac.startStream();
}

void MainWindow::on_pushButton_stop_clicked()
{
    isPlaying = false;
    dac.stopStream();
    if ( askSave() )
        doSave();
    vsamps.clear();
}

void MainWindow::plot()
{
    QVector<MY_TYPE> qx( kRTABUFFER_SZ );
    QVector<MY_TYPE> qy( kRTABUFFER_SZ );

    for ( int i = 0; i < kRTABUFFER_SZ; ++i )
    {
        qx[ i ] = i; // x goes from -1 to 1
        qy[ i ] = plot_buffer[ i ];
    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph( 0 )->setData( qx, qy );
    ui->customPlot->xAxis->setRange( 0, kRTABUFFER_SZ - 1 );
    ui->customPlot->yAxis->setRange( -1, 1 );
    ui->customPlot->replot();
}

void MainWindow::updatePlot( eWaveType e )
{
    if ( e == esine )
        doPlotSine();
    else if ( e == esquare )
        doPlotSquareBL();
    else if ( e == esawup )
        doPlotSawUpBL();
    else if ( e == esawdown )
        doPlotSawDownBL();
    else if ( e == etriangle )
        doPlotTriangleBL();

    plot();
}

void MainWindow::on_horizontalSlider_freq_valueChanged( int value )
{
    hSlider_freq = value;
    ui->label_freqValue->setNum( value );
    setNyquistMaxHarm( value );

    if ( isPlaying )
    {
        updatePlot( ewave );
    }
}

void MainWindow::on_horizontalSlider_amp_valueChanged( int value )
{
    hSlider_ampl = static_cast<MY_TYPE>( value / 100.0 );
    ui->label_ampValue->setNum( static_cast<double>( hSlider_ampl ) );

    if ( isPlaying )
    {
        updatePlot( ewave );
    }
    /*
    qDebug() << "You need to display the dB value of the amplitude in the label";
    */
}

void MainWindow::updateWaveformFlags( QRadioButton* rb )
{
    isSine = false;
    isSquare = false;
    isSawUp = false;
    isSawDown = false;
    isTriangle = false;

    if ( rb == ui->radioButton_sine )
    {
        isSine = true;
        ewave = esine;
        updatePlot( esine );
    }
    else if ( rb == ui->radioButton_square )
    {
        isSquare = true;
        ewave = esquare;
        updatePlot( esquare );
    }
    else if ( rb == ui->radioButton_sawup )
    {
        isSawUp = true;
        ewave = esawup;
        updatePlot( esawup );
    }
    else if ( rb == ui->radioButton_sawdown )
    {
        isSawDown = true;
        ewave = esawdown;
        updatePlot( esawdown );
    }
    else if ( ui->radioButton_triangle )
    {
        isTriangle = true;
        ewave = etriangle;
        updatePlot( etriangle );
    }

    dac.stopStream();
    updatePlot( ewave );
    dac.startStream();
}
void MainWindow::on_radioButton_sine_toggled( bool checked )
{
    if ( checked )
    {
        isPlaying = true;
        updateWaveformFlags( ui->radioButton_sine );
    }
}

void MainWindow::on_radioButton_square_toggled( bool checked )
{
    if ( checked )
    {
        isPlaying = true;
        updateWaveformFlags( ui->radioButton_square );
    }
}

void MainWindow::on_radioButton_sawup_toggled( bool checked )
{
    if ( checked )
    {
        isPlaying = true;
        updateWaveformFlags( ui->radioButton_sawup );
    }
}

void MainWindow::on_radioButton_sawdown_toggled( bool checked )
{
    if ( checked )
    {

        isPlaying = true;
        updateWaveformFlags( ui->radioButton_sawdown );
    }
}

void MainWindow::on_radioButton_triangle_toggled( bool checked )
{
    if ( checked )
    {
        isPlaying = true;
        updateWaveformFlags( ui->radioButton_triangle );
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    ++hSlider_freq;
    ui->horizontalSlider_freq->setValue( static_cast<int>( hSlider_freq ) );
    ui->label_freqValue->setNum( hSlider_freq );
    if ( isPlaying )
    {
        updatePlot( ewave );
    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    --hSlider_freq;
    ui->horizontalSlider_freq->setValue( static_cast<int>( hSlider_freq ) );
    ui->label_freqValue->setNum( static_cast<int>( hSlider_freq ) );
    if ( isPlaying )
    {
        updatePlot( ewave );
    }
}

void MainWindow::on_horizontalSlider_harm_valueChanged( int value )
{
    hSlider_numHarmonics = value;
    if ( ( ewave == esquare ) || ( ewave == etriangle ) )
    {
        if ( value % 2 == 0 ) // even number
        {
            ui->horizontalSlider_harm->setValue( value + 1 );
            ui->label_harmValue->setNum( value + 1 );
        }
    }
    else
    {
        ui->horizontalSlider_harm->setValue( value );
        ui->label_harmValue->setNum( value );
    }
    setNyquistMaxHarm( hSlider_freq );
    if ( isPlaying )
    {
        updatePlot( ewave );
    }
}

bool MainWindow::askSave()
{
    qDebug() << "You need to implement askSave()\nSee class web page";
    return false;
}

void MainWindow::doSave()
{
    qDebug() << "You need to implement doSave()\nUse wavio.h and .cpp";
}
