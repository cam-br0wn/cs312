#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef WAVETABLES_H
#include "waveTables.h"
#endif

#include <QMainWindow>

#include <vector>

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
    void on_pushButton_generate_clicked();

    void on_pushButton_save_clicked();

    void on_verticalSlider_frequency_valueChanged( int value );

    void on_pushButton_truncate_clicked();

    void on_pushButton_round_clicked();

    void on_pushButton_interpolate_clicked();

    void on_verticalSlider_wavetable_valueChanged( int value );

    void on_verticalSlider_amplitude_valueChanged( int value );

    void on_horizontalScrollBar_zoom_valueChanged( int value );

  private:
    Ui::MainWindow* ui;

    bool isTruncate;
    bool isRound;
    bool isInterpolate;

    int tableSize;
    int frequency;
    MY_TYPE amplitude;
    std::vector<MY_TYPE> vFileSamples;

    void initControls();
    void plot( std::vector<MY_TYPE> v );
};

#endif // MAINWINDOW_H
