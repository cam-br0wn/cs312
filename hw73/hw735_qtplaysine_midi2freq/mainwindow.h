#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

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
    void on_pushButton_stop_clicked();

private:
    Ui::MainWindow* ui;

    RtAudio dac;
    void init_controls();
    void open_dac_stream();
};
#endif // MAINWINDOW_H
