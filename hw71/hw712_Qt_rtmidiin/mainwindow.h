#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

#ifndef RTMIDI_H
#include "RtMidi.h"
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    RtMidiIn* gmidiin;
    RtMidiOut* gmidiout;

    void init_midi_in( uint32_t num );
    void init_midi_out( uint32_t num );

};

extern QPlainTextEdit* pte;

#endif // MAINWINDOW_H
