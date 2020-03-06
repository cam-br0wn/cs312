#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef WAVIO_H
#include "wavio.h"
#endif

#ifndef WAVSTATS_H
#include "wavstats.h"
#endif

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
    displayStats( ui->plainTextEdit_stats );

    plot();
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

void MainWindow::on_horizontalScrollBar_zoom_valueChanged(int value)
{
    // scaling based on vsamps.size() and value parameter
      ui->customPlot->xAxis->setRange( 0, vsamps.size() - (vsamps.size() * value / 100));
      ui->customPlot->replot();
}

void MainWindow::plot()
{
    // generate some data:
//   QVector<double> x( 101 ), y( 101 ); // initialize with entries 0..100
//   for ( int i = 0; i < 101; ++i )
//   {
//       x[ i ] = i / 50.0 - 1;    // x goes from -1 to 1
//       y[ i ] = x[ i ] * x[ i ]; // let's plot a quadratic function
//   }
//   // create graph and assign data to it:
//   ui->customPlot->addGraph();
//   ui->customPlot->graph( 0 )->setData( x, y );
//   // give the axes some labels:
//   ui->customPlot->xAxis->setLabel( "x" );
//   ui->customPlot->yAxis->setLabel( "y" );
//   // set axes ranges, so we see all data:
//   ui->customPlot->xAxis->setRange( -1, 1 );
//   ui->customPlot->yAxis->setRange( 0, 1 );
//   ui->customPlot->replot();

   // generate some data:
    size_t sz = vsamps.size();
    QVector<MY_TYPE> x(sz); // the n sample indices on the x axis = vsamps.size()
    QVector<MY_TYPE> y(sz); // the n sample values on the y axis for each vsamp[n]


  // The for loop for the x and y axes needs to be revised.
    for ( int i = 0; i < sz; ++i )
    {
        x[ i ] = i;
        y[ i ] = vsamps.at(i);
    }


    //create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);


    /* JE
    // give the axes some labels:
    //  customPlot->xAxis->setLabel("x");
    // customPlot->yAxis->setLabel("y");
    */

    // set axes ranges, so we see all data
   // set axes ranges, so we see all data:
       ui->customPlot->xAxis->setRange( -1, 1 );
       ui->customPlot->yAxis->setRange( 0, 1 );

//    These two lines need to be adjusted based on how much of the waveform is being plotted.
//    When a file is first opened the x axis ranges from 0 to sz-1 \\
//    and the y axis ranges from -1 t0 +1.

//    After that use the on_horizontalScrollBar_zoom_valueChanged( int value ) function change the xAxis range
       ui->customPlot->replot();
}
