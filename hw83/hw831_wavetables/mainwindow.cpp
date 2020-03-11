#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

#include <cmath>

MainWindow::MainWindow( QWidget* parent )
    : QMainWindow( parent ),
      ui( new Ui::MainWindow ),
/*
        continue initializing class variables
        in the order they appear in the .h file
                isTruncate to false
                isRound to false
                isInterpolate to false
                tableSize to 8
                frequency to 4
                amplitude to 0.9
      */
    isTruncate{false},
    isRound{false},
    isInterpolate{false},
    tableSize{8},
    frequency{4},
    amplitude{0.9}

{
    ui->setupUi( this );
    /*
     reserve 4096 bytes for vector vFileSamples
     initControls()
    */
    vFileSamples.reserve(4096);
    initControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initControls()
{
    /*
    verticalSlider_wavetable to 3
    label_tablesizeValue to tableSize

    verticalSlider_amplitude to amplitude*100
    label_amplitudeValue to amplitude

    verticalSlider_frequency to frequency
    label_frequencyValue to frequency

    horizontalScrollBar_zoom to 100
*/

    ui->verticalSlider_wavetable->setValue(3);
    ui->label_tablesizeValue->setNum(tableSize);

    ui->verticalSlider_amplitude->setValue(amplitude*100);
    ui->label_amplitudeValue->setNum(amplitude);

    ui->verticalSlider_frequency->setValue(frequency);
    ui->label_frequencyValue->setNum(frequency);

    ui->horizontalScrollBar_zoom->setValue(100);
}

void MainWindow::on_pushButton_generate_clicked()
{
    /*
            set isTruncate to true
            set isRound to false
            set isInterpolate to false

            call create_wavetable( tableSize) and return variable vtable
            call truncateWavetable( vtable, amplitude, frequency, 1.0 ) and return variable v
            call plot(v)
            set vector vFileSamples = v
      */
    isTruncate = true;
    isRound = false;
    isInterpolate = false;

    std::vector<MY_TYPE> vtable = create_wavetable(tableSize);
    std::vector<MY_TYPE> v = truncateWavetable(vtable, amplitude, frequency, 1.0);
    plot(v);
    vFileSamples = v;

}

void MainWindow::on_pushButton_save_clicked()
{
    QString fname = QFileDialog::getSaveFileName();
    writeWav(fname.toStdString(), vFileSamples);
}

void MainWindow::plot( std::vector<MY_TYPE> v )
{
    /*
            create an int variable sz equals v.size() using static_cast
            declare QVector<MY_TYPE> qx with size sz
            declare QVector<MY_TYPE> qy with size sz

            loop-begin through sz elements
                set each qx to loop index value
                set each qy to v.at( loop index value)
            loop-end

            // create graph and assign data to it:
            call customPlot addGraph();
            call customPlot graph( 0 )->setData( qx, qy );
            // set axes ranges, so we see all data:
            call customPlot xAxis->setRange( 0, v.size() );
            call customPlot yAxis->setRange( -1, 1 );
            call customPlot replot();
        */
    int sz = static_cast<int>(v.size());
    QVector<MY_TYPE> qx(sz);
    QVector<MY_TYPE> qy(sz);

    for(int s = 0; s < sz; ++s){
        qx[s] = s;
        qy[s] = v.at(s);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(qx,qy);

    ui->customPlot->xAxis->setRange(0,v.size());
    ui->customPlot->yAxis->setRange(-1,1);
    ui->customPlot->replot();

}

void MainWindow::on_pushButton_truncate_clicked()
{
    /*
            set isTruncate to true
            set isRound to false
            set isInterpolate to false
            create double freq variable
            if checkBox_440 is checked
                freq is 440
            else 
                freq is frequency

            call create_wavetable( tableSize) and return variable vtable
            call truncateWavetable( vtable, amplitude, freq, 1.0 ) and return variable v
            call plot(v)
            set vector vFileSamples = v
        */
    isTruncate = true;
    isRound = false;
    isInterpolate = false;
    double freq;
    if(ui->checkBox_440->isChecked())
    {
        freq = 440;
    }
    else
    {
        freq = frequency;
    }
    std::vector<MY_TYPE> vtable = create_wavetable(tableSize);
    std::vector<MY_TYPE> v = truncateWavetable(vtable, amplitude, freq, 1.0);
    plot(v);
    vFileSamples = v;
}

void MainWindow::on_pushButton_round_clicked()
{
    // similar to on_pushButton_truncate_clicked using std::round instead of std::floor
    isTruncate = false;
    isRound = true;
    isInterpolate = false;
    double freq;
    if(ui->checkBox_440->isChecked())
    {
        freq = 440;
    }
    else
    {
        freq = frequency;
    }
    std::vector<MY_TYPE> vtable = create_wavetable(tableSize);
    std::vector<MY_TYPE> v = roundWavetable(vtable, amplitude, freq, 1.0);
    plot(v);
    vFileSamples = v;

}

void MainWindow::on_pushButton_interpolate_clicked()
{
    // similar to on_pushButton_truncate_clicked but using the linear interpolation
    // formula from the web page
//    doMessageBox( "You clicked pushButton_interpolate" );

    isTruncate = false;
    isRound = false;
    isInterpolate = true;
    double freq;
    if(ui->checkBox_440->isChecked())
    {
        freq = 440;
    }
    else
    {
        freq = frequency;
    }
    std::vector<MY_TYPE> vtable = create_wavetable(tableSize);
    std::vector<MY_TYPE> v = interpolateWavetable(vtable, amplitude, freq, 1.0);
    plot(v);
    vFileSamples = v;
}

void MainWindow::on_verticalSlider_wavetable_valueChanged( int value )
{

    /*
            slider range is 1-12

            set tableSize to std::pow(2,value)
            set label_tablesizeValue to tableSize
            if else statements to call
                on_pushButton_truncate_clicked();
                on_pushButton_round_clicked();
                on_pushButton_interpolate_clicked();
                on_pushButton_generate_clicked();
        */
    tableSize = std::pow(2, value);
    ui->label_tablesizeValue->setNum(tableSize);
    if(isTruncate){
        on_pushButton_truncate_clicked();
    }
    else if(isRound){
        on_pushButton_round_clicked();
    }
    else if(isInterpolate){
        on_pushButton_interpolate_clicked();
    }
    else if(ui->pushButton_generate->isDown()){
        on_pushButton_generate_clicked();
    }
}

void MainWindow::on_verticalSlider_amplitude_valueChanged( int value )
{
    /*
            slider range is 0-100

            set amplitude as value * 0.01 to keep range between 0-1.0
            set label_amplitudeValue to amplitude
            if isTruncate call on_pushButton_truncate_clicked()
     */
    amplitude = value * .01;
    ui->label_amplitudeValue->setNum(amplitude);
    if(isTruncate){
        on_pushButton_truncate_clicked();
    }
    else if(isRound){
        on_pushButton_round_clicked();
    }
    else if(isInterpolate){
        on_pushButton_interpolate_clicked();
    }
    else if(ui->pushButton_generate->isDown()){
        on_pushButton_generate_clicked();
    }
}

void MainWindow::on_verticalSlider_frequency_valueChanged( int value )
{
    /*
            slider range is 1-50

            set frequency to value
            set label_frequencyValue to frequency
            if isTruncate call on_pushButton_truncate_clicked()
     */
    frequency = value;
    ui->label_frequencyValue->setNum(frequency);
    if(isTruncate){
        on_pushButton_truncate_clicked();
    }
    else if(isRound){
        on_pushButton_round_clicked();
    }
    else if(isInterpolate){
        on_pushButton_interpolate_clicked();
    }
    else if(ui->pushButton_generate->isDown()){
        on_pushButton_generate_clicked();
    }
}

void MainWindow::on_horizontalScrollBar_zoom_valueChanged( int value )
{
    /*
            slider range is 1-100

    call customPlot xAxis setRange from 0 to (value * 100 );
    call customPlot replot
        */
    ui->customPlot->xAxis->setRange(0, value * 100);
    ui->customPlot->replot();
}
