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
    init_controls();
    open_dac_stream();


/*-------------------------------------------------
 init_controls()
 open_dac_stream() but don't call startStream()
-------------------------------------------------*/
}

MainWindow::~MainWindow()
{
    delete ui;
    if (dac.isStreamOpen()) {
        dac.closeStream();
    }
/*-------------------------------------------------
if dac.isStreamOpen() then close it
-------------------------------------------------*/
}

void MainWindow::init_controls()
{


/*-------------------------------------------------
set these controls to their default values
horizontalSlider_freq
horizontalSlider_amp
label_freqValue
label_ampValue
-------------------------------------------------*/
    ui->horizontalSlider_freq->setValue(220);
    ui->horizontalSlider_freq->setRange(20, 4000);
    ui->horizontalSlider_amp->setValue(50);
    ui->horizontalSlider_freq->setRange(0, 100);

    ui->label_freq->setText("Frequency Hz");
    ui->label_amp->setText("Amplitude");

   // ui->label_ampValue = ui->horizontalSlider_amp->

}

void MainWindow::open_dac_stream()
{

 QApplication::processEvents();

/*-------------------------------------------------
figure it out
don't forget about QApplication::processEvents();
-------------------------------------------------*/
}

void MainWindow::close_dac_stream()
{


/*-------------------------------------------------
figure it out
-------------------------------------------------*/
}

// Use right-click "Go to Slot" on the control in Design view
void MainWindow::on_pushButton_play_clicked()
{


/*-------------------------------------------------
figure it out
-------------------------------------------------*/
}

// Use right-click "Go to Slot" on the control in Design view
void MainWindow::on_pushButton_stop_clicked()
{

/*-------------------------------------------------
figure it out
-------------------------------------------------*/
}

// Use right-click "Go to Slot" on the control in Design view
void MainWindow::on_horizontalSlider_freq_valueChanged( int value )
{
/*-------------------------------------------------
figure it out
remember to update label_freqValue whenever the slider moves
-------------------------------------------------*/
}

// Use right-click "Go to Slot" on the control in Design view
void MainWindow::on_horizontalSlider_amp_valueChanged( int value )
{
/*-------------------------------------------------
figure it out
remember to update label_ampValue whenever the slider moves
remember code and label_ampValue use/display values as 0.0-1.0
-------------------------------------------------*/
}

void MainWindow::on_pushButton_stop_clicked()
{

}
