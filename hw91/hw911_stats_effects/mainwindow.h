#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QString>

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

extern RtAudio dac;
extern bool isPlaying;

// extern std::vector<MY_TYPE> vplay;

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

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_radioButton_removedc_clicked();

    void on_radioButton_normalize_clicked();

    void on_radioButton_amplify_clicked();

    void on_radioButton_reverse_clicked();

    void on_radioButton_echo_clicked();

    void on_radioButton_changespeed_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_Play_clicked();

    void on_pushButton_quit_clicked();

    void on_horizontalSlider_speedChange_valueChanged( int value );

    void on_pushButton_apply_clicked();

    void on_verticalSlider_amplify_valueChanged( int value );

    void on_horizontalSlider_echonum_valueChanged( int value );

    void on_horizontalSlider_echodelay_valueChanged( int value );

    void on_horizontalSlider_echodamp_valueChanged( int value );

    void on_horizontalSlider_maxlen_valueChanged( int value );

    void on_horizontalSlider_reps_valueChanged( int value );

    void on_radioButton_randomsnips_clicked();

    void on_pushButton_stop_clicked();

  private:
    Ui::MainWindow* ui;

    QString qOpenFileName;
    QString qSaveAsFileName;

    void open_dac_stream();
};
#endif // MAINWINDOW_H
