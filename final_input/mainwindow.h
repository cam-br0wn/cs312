#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RtMidi.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <random>

extern int baseNote; // the current base note of the arpeggio
extern int bpm; // the current bpm of the arpeggio
extern int arp_length; // the number of notes in the arpeggio
extern int volume; // the volume of the output
extern bool isMajor; // if it is a major scale arpeggio
extern int octave; // the base octave of the arpeggio
extern int arp_type; // type of arpeggio (0 = up, 1 = down, 2 = updown, 3 = random)
extern bool isPlaying;
extern int patch;
extern std::vector<int> varp; // vector containing arpeggio samples


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void playTrack();

    void generateArp();

    void on_volume_slider_valueChanged(int value);

    void on_arp_rate_slider_valueChanged(int value);

    void on_arp_notes_slider_valueChanged(int value);

    void on_major_button_clicked(bool checked);

    void on_minor_button_clicked(bool checked);

    void on_C_key_pressed();

    void on_Csharp_key_pressed();

    void on_D_key_pressed();

    void on_Dsharp_key_pressed();

    void on_E_key_pressed();

    void on_F_key_pressed();

    void on_Fsharp_key_pressed();

    void on_G_key_pressed();

    void on_Gsharp_key_pressed();

    void on_A_key_pressed();

    void on_Asharp_key_pressed();

    void on_B_key_pressed();

    void on_stop_button_pressed();

    void on_arp_type_select_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_instrument_select_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
