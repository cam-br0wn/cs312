#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

#include <cmath> // for M_PI
#include <iostream>

/*-------------------------------------------------
 two new variables
-------------------------------------------------*/
RtAudio dac;
bool isPlaying = true;

// One-channel sine wave generator replaces saw callback function
// unchanged
int sine( void* outputBuffer, void* inputBuffer, unsigned int nBufferFrames,
          double streamTime, RtAudioStreamStatus status, void* userData )
{
    MY_TYPE* buffer = ( MY_TYPE* )outputBuffer;
    if ( status )
        std::cout << "Stream underflow detected!" << std::endl;
    static MY_TYPE phz = 0;
    MY_TYPE freq = 440.0;
    MY_TYPE amp = 1.0;
    // //phase increment formula
    const MY_TYPE phzinc = k2PIT * freq;
    for ( uint32_t i = 0; i < nBufferFrames; i++ )
    {
        *buffer++ = amp * sin( phz );
        phz += phzinc;
        if ( phz >= k2PI )
            phz -= k2PI;
    }
    rta.frameCounter += nBufferFrames;
    if ( rta.checkCount && ( rta.frameCounter >= rta.nFrames ) )
        return callbackReturnValue;
    return 0;
}



MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::MainWindow )
{
    ui->setupUi( this );
//    std::cout << "MainWindow()" << std::endl;
    init_controls();
    open_dac_stream();
}

MainWindow::~MainWindow()
{
    delete ui;
    close_dac_stream();
}

void MainWindow::init_controls()
{
    ui->horizontalSlider_freq->setValue(220);
    ui->horizontalSlider_amp->setValue(50);
    ui->label_freqValue->setNum(220);
    ui->label_ampValue->setNum(50);
}

void MainWindow::open_dac_stream()
{
//    std::cout << "open_dac_stream()" << std::endl;

    if (dac.getDeviceCount() < 1)
    {
       std::cout << "\nNo audio devices found!\n";
       exit(1);
    }

    MY_TYPE *data = (MY_TYPE *)calloc(rta.channels, sizeof(MY_TYPE));

    dac.showWarnings(true);

    if (rta.device == 0)
        oParams.deviceId = dac.getDefaultOutputDevice();

    try
    {
        dac.openStream(&oParams, NULL, FORMAT, rta.fs, &rta.bufferFrames, &sine, (void *)data, &options, &errorCallback);
    }
    catch (RtAudioError &e)
    {
        e.printMessage();
        close_dac_stream();
    }
}

void MainWindow::close_dac_stream()
{
    if (dac.isStreamOpen())
        dac.closeStream();
}

void MainWindow::on_pushButton_play_clicked()
{
    try
    {
        dac.startStream();
    }
    catch (RtAudioError &e)
    {
        e.printMessage();
        close_dac_stream();
    }
}

void MainWindow::on_pushButton_stop_clicked()
{
    dac.stopStream();
}

void MainWindow::on_horizontalSlider_freq_valueChanged( int value )
{
    ui->label_freqValue->setNum(value);
}

void MainWindow::on_horizontalSlider_amp_valueChanged( int value )
{
     ui->label_ampValue->setNum(value * 0.01);
}


