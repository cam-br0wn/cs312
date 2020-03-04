#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef GLOBALS_H_
#include "globals.h"
#endif

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

#include <QColor>
#include <QMainWindow>
#include <QRadioButton>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget* parent = nullptr );
    ~MainWindow();

  private slots:
    void on_pushButton_play_clicked();

    void on_pushButton_stop_clicked();

    void on_horizontalSlider_freq_valueChanged( int value );

    void on_horizontalSlider_amp_valueChanged( int value );

    void on_radioButton_square_toggled( bool checked );

    void on_radioButton_sine_toggled( bool checked );

    void on_radioButton_sawup_toggled( bool checked );

    void on_radioButton_sawdown_toggled( bool checked );

    void on_radioButton_triangle_toggled( bool checked );

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_horizontalSlider_harm_valueChanged( int value );

  private:
    Ui::MainWindow* ui;

    bool askSave();
    void doSave();
    void init_controls();
    void open_dac_stream();
    void plot();
    void updatePlot( eWaveType e );
    void updateWaveformFlags( QRadioButton* rb );
    void setNyquistWarning( QColor color );
    void setNyquistMaxHarm( MY_TYPE freq );
};
#endif // MAINWINDOW_H
