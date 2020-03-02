#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef WAVIO_H
#include "wavio.h"
#endif

#include "wavstats.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QMediaPlayer>

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::MainWindow )
{
    ui->setupUi( this );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{


    /*
       * Call QFileDialog::getOpenFileName
       * Set qCurrentOpenFileName
       * Set label_filename to the name of the file opened
    */

    QString dir = "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/cs312/hw81/hw81_wav";
    qOpenFileName = QFileDialog::getOpenFileName( this, tr( "Open File" ), dir, tr( "Wav file( *.wav )" ) );

    ui->label_filename->setText(qOpenFileName);

    std::string file_path = qOpenFileName.toStdString();
    readWav(file_path);

    vsamps = readWav( qOpenFileName.toStdString() );

    displaySF_INFO( ui->plainText_sinfo );
}

void MainWindow::on_actionSave_as_triggered()
{

    /*
   * Call QFileDialog::getSaveFileName
   * Copy writeWav() from hw811
   * Set qCurrentSaveAsFileName
   */

    QString dir = "/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/cs312/hw81/hw81_wav";
    qSaveAsFileName = QFileDialog::getSaveFileName(this, tr("Save File"), dir, tr("Wav file( *.wav )" ));
    writeWav(qSaveAsFileName.toStdString(), vsamps);

    //readWav(qSaveAsFileName);

//    SndfileHandle (std::string const & path, int mode = SFM_WRITE) ;

}

void MainWindow::on_pushButton_play_clicked()
{
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(qOpenFileName));
    player->setVolume(1000);
    player->play();
}

void MainWindow::doMessageBox( const QString& qs )
{
    // copied directly from the Help page for MessageBox
    QMessageBox msgBox;
    msgBox.setText( qs );
    msgBox.exec();
}
