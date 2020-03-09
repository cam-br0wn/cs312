#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef WAVSTATS_H
#include "wavstats.h"
#endif

#ifndef WAVEFFECTS_H
#include "waveffects.h"
#endif

#include <QDebug>
#include <QFileDialog>

RtAudio dac;
bool isPlaying = false;
static size_t count{0};

int rtCallback( void* outputBuffer, void* /*inputBuffer*/, unsigned int nBufferFrames,
                double /*streamTime*/, RtAudioStreamStatus status, void* /*userData*/ )
{
    MY_TYPE* buffer = static_cast<MY_TYPE*>( outputBuffer );
    if ( status )
        std::cout << "Stream underflow detected!" << std::endl;

    for ( unsigned int n = 0; n < nBufferFrames; n++ )
    {
        *buffer = veffect.at( count );
        ++buffer;
        ++count;
    }

    QApplication::processEvents();

    rta.frameCounter += nBufferFrames;

    if ( rta.checkCount && ( rta.frameCounter >= rta.nFrames ) )
        return callbackReturnValue;
    else if ( count >= veffect.size() - kRTABUFFER_SZ + 1 )
        return callbackReturnValue;

    return 0;
}

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::MainWindow ),
      qOpenFileName{""},
      qSaveAsFileName{""}
{
    ui->setupUi( this );

    ui->stackedWidget->setCurrentIndex( 0 );
    ui->radioButton_removedc->setChecked( false );

    open_dac_stream();
}

MainWindow::~MainWindow()
{
    delete ui;

    if ( dac.isStreamOpen() )
        dac.closeStream();
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
       dac.openStream( &oParams, nullptr, FORMAT, rta.fs, &rta.bufferFrames, rtCallback, static_cast<void*>( data ), &options, &errorCallback );

       while ( isPlaying )
       {
           QApplication::processEvents();
       }
}

void MainWindow::on_actionOpen_triggered()
{
    // Change to your dir
    QString dir = "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/cs312/hw91/hw911_stats_effects";
    QString qs = QFileDialog::getOpenFileName( this, tr( "Open File" ),
                                               dir,
                                               tr( "Wav file( *.wav )" ) );

    qOpenFileName = qs;

    ui->stackedWidget->setCurrentIndex( 0 );
    ui->radioButton_removedc->setChecked( true );

    ui->plainTextEdit_sfinfo->clear();
    ui->plainTextEdit_stats->clear();

    vsamps = readWav( qs.toStdString() );
    ui->label_filename->setText( qs );

    displaySF_INFO( ui->plainTextEdit_sfinfo );
    displayStats( ui->plainTextEdit_stats );
    veffect = vsamps;
}

void MainWindow::on_actionSave_As_triggered()
{
    // Change to your dir
    QString dir = "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/cs312/hw91/hw911_stats_effects";
    QString qs = QFileDialog::getSaveFileName( this, tr( "Save File" ),
                                               dir,
                                               tr( "Wav file (*.wav)" ) );

    qSaveAsFileName = qs;
    writeWav( qs.toStdString(), veffect );
}

void MainWindow::on_radioButton_removedc_clicked()
{
    ui->stackedWidget->setCurrentIndex( 0 );
    doMessageBox( "mainwindow.cpp\n\nRemove DC clicked" );
}

void MainWindow::on_radioButton_normalize_clicked()
{
    ui->stackedWidget->setCurrentIndex( 1 );
    doMessageBox( "mainwindow.cpp\n\nNormalize clicked" );
}

void MainWindow::on_radioButton_amplify_clicked()
{
    ui->stackedWidget->setCurrentIndex( 2 );
    ui->verticalSlider_amplify->setValue( 50 );
    ui->doubleSpinBox_amplify->setValue( 0.50 );

    doMessageBox( "mainwindow.cpp\n\nAmplify clicked" );
}

void MainWindow::on_radioButton_reverse_clicked()
{
    ui->stackedWidget->setCurrentIndex( 3 );
    doMessageBox( "mainwindow.cpp\n\nReverse clicked" );
}

void MainWindow::on_radioButton_echo_clicked()
{
    ui->stackedWidget->setCurrentIndex( 4 );
    ui->horizontalSlider_echonum->setValue( 4 );
    ui->label_echonumval->setNum( echo_num );

    ui->horizontalSlider_echodelay->setValue( echo_delay );
    ui->label_echodelayval->setNum( echo_delay );

    ui->horizontalSlider_echodamp->setValue( echo_damp * 100 );
    ui->label_echodampval->setNum( echo_damp );
    doMessageBox( "mainwindow.cpp\n\nEcho clicked" );
}

void MainWindow::on_radioButton_changespeed_clicked()
{
    ui->stackedWidget->setCurrentIndex( 5 );
    ui->label_speedVal->setNum( 1.0 );
    doMessageBox( "mainwindow.cpp\n\nChange Speed clicked" );
}

void MainWindow::on_radioButton_randomsnips_clicked()
{
    ui->stackedWidget->setCurrentIndex( 6 );
}

void MainWindow::on_pushButton_open_clicked()
{
    on_actionOpen_triggered();
}

void MainWindow::on_pushButton_save_clicked()
{
    on_actionSave_As_triggered();
}

void MainWindow::on_pushButton_quit_clicked()
{
    isPlaying = false;
    QApplication::quit();
}

void MainWindow::on_pushButton_Play_clicked()
{
    count = 0;
    isPlaying = true;

    dac.startStream();
}

void MainWindow::on_horizontalSlider_speedChange_valueChanged( int value )
{
    MY_TYPE val = value / 10.0;
    if ( val < 0 )
        val = 0.1;

    ui->label_speedVal->setNum( val );
    changeSpeed_rate = val;
}

void MainWindow::on_pushButton_apply_clicked()
{
    switch ( ui->stackedWidget->currentIndex() )
    {
    case 0:
        doRemoveDC();
        break;
    case 1: //
        doNormalize( ui->doubleSpinBox_normalize->value() );
        break;
    case 2:
        doAmplify( ui->doubleSpinBox_amplify->value() );
        break;
    case 3:
        doReverse();
        break;
    case 4:
        doEchos();
        break;
    case 5:
        doChangeSpeed( changeSpeed_rate );
        break;
    case 6:
        doRandomSnips( ui->label_secondsval );
        break;
    }
}

void MainWindow::on_verticalSlider_amplify_valueChanged( int value )
{
    ui->doubleSpinBox_amplify->setValue( value / 100.0 );
}

void MainWindow::on_horizontalSlider_echonum_valueChanged( int value )
{
    echo_num = value;
    ui->label_echonumval->setNum( value );
}

void MainWindow::on_horizontalSlider_echodelay_valueChanged( int value )
{
    echo_delay = value;
    ui->label_echodelayval->setNum( value );
}

void MainWindow::on_horizontalSlider_echodamp_valueChanged( int value )
{
    echo_damp = value * .01;
    ui->label_echodampval->setNum( echo_damp );
}

void MainWindow::on_horizontalSlider_maxlen_valueChanged( int value )
{
    snip_maxLen = value;
    ui->label_maxlenvalue->setNum( value );
}

void MainWindow::on_horizontalSlider_reps_valueChanged( int value )
{
    snip_reps = value;
    ui->label_repsvalue->setNum( value );
}

void MainWindow::on_pushButton_stop_clicked()
{
    if ( dac.isStreamRunning() )
        dac.stopStream();
}
