#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RtMidi.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <random>

#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )

int baseNote{48}; // the current base note of the arpeggio
int bpm{120}; // the current bpm of the arpeggio
int arp_length{6}; // the number of notes in the arpeggio
int volume{100}; // the volume of the output
bool isMajor{true}; // if it is a major scale arpeggio
int octave{4}; // the base octave of the arpeggio
int arp_type{0}; // the type of arpeggio (0 = up, 1 = down, 2 = updown, 3 = random)
bool isPlaying{false}; // boolean to determine if the arp should be playing
int patch{0}; // patch number

std::vector<int> varp; // vector containing arp notes

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
 * generateArp
 * This is a method to stuff varp with the integer values
 * that represent each pitch in the arpeggio. Almost every
 * time a setting is changed on the GUI, this method is called,
 * and at the end of it, playTrack is called
 */
void MainWindow::generateArp(){

    varp.clear();

    int curr_note = baseNote;

    for(int i = 0; i < arp_length; i++){
        varp.push_back(curr_note);
        if(isMajor){
            if(i % 3 == 0){
                curr_note += 4;
            }
            else if(i % 3 == 1){
                curr_note += 3;
            }
            else{
                curr_note += 5;
            }
        }
        else{
            if(i % 3 == 0){
                curr_note += 3;
            }
            else if(i % 3 == 1){
                curr_note += 4;
            }
            else{
                curr_note += 5;
            }
        }
    }

    if(arp_type == 1){
        std::reverse(varp.begin(), varp.end());
    }
    else if(arp_type == 2){
        for(int i = varp.size() - 2; i > 0; i--){
            varp.push_back(varp.at(i));
        }
    }
    else if(arp_type == 3){
        // code borrowed from:
        // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(varp), std::end(varp), rng);
    }

    playTrack();

}
/*
 * playTrack
 * This is a method to play the generated arpeggio
 * using RtMidi. The RtMidi reference we heavily based this method off of is:
 * https://www.music.mcgill.ca/~gary/rtmidi/
 * Specifically the MIDI Output section
 */
void MainWindow::playTrack(){

    RtMidiIn *midiin = 0;

    // RtMidiIn constructor
    try {
      midiin = new RtMidiIn();
    }
    catch ( RtMidiError &error ) {
      error.printMessage();
      exit( EXIT_FAILURE );
    }

    // Check inputs.
      unsigned int nPorts = midiin->getPortCount();
      std::cout << "\nThere are " << nPorts << " MIDI input sources available.\n";
      std::string portName;
      for ( unsigned int i=0; i<nPorts; i++ ) {
        try {
          portName = midiin->getPortName(i);
        }
        catch ( RtMidiError &error ) {
          error.printMessage();
        }
        std::cout << "  Input Port #" << i+1 << ": " << portName << '\n';
      }

    RtMidiOut *midiout = new RtMidiOut();
    std::vector<unsigned char> message;
    // Check available ports.
      nPorts = midiout->getPortCount();
      if ( nPorts == 0 ) {
        std::cout << "No ports available!\n";
      }
    midiout->openPort(0);

    // reset all controllers to default state
    message.push_back(0xb0);
    message.push_back(121);
    message.push_back(0);

    // Patch change: C0, 5
    message[0] = 0xc0;
    message[1] = patch;
    midiout->sendMessage( &message );

    // Control Change: B0, 7, 100 (volume)
    message[0] = 0xB0;
    message[1] = 7;
    message[2] = 100;
    midiout->sendMessage( &message );

    int note_count{0};
    int curr_pitch{baseNote};

    while(isPlaying){
        curr_pitch = varp[note_count % varp.size()]; // essentially loops through the varp vector

        // NON
        message[0] = 0x90;
        message[1] = curr_pitch;
        message[2] = volume;
        midiout->sendMessage( &message );

        SLEEP( ((1.0 / (bpm / 30.0)) * 250.0)); // because RtMidi doesn't have any timestamp implementation, it is necessary to use SLEEP, as defined in the RtMidi example code

        //NOF
        message[0] = 0x80;
        message[1] = curr_pitch;
        message[2] = 0;
        midiout->sendMessage( &message );

        SLEEP( ((1.0 / (bpm / 30.0)) * 250.0));

        note_count++;

        QApplication::processEvents(); // ensures that user input on the GUI can still be taken while the arp is playing

    }

}

void MainWindow::on_volume_slider_valueChanged(int value)
{
    ui->volume_reading->setNum(value);
    volume = value;
}

void MainWindow::on_arp_rate_slider_valueChanged(int value)
{
    ui->arp_rate_reading->setNum(value);
    bpm = value;
}

void MainWindow::on_arp_notes_slider_valueChanged(int value)
{
    ui->arp_notes_reading->setNum(value);
    arp_length = value;
    generateArp();
}

void MainWindow::on_major_button_clicked(bool checked)
{
    isMajor = checked;
    generateArp();
}

void MainWindow::on_minor_button_clicked(bool checked)
{
    isMajor = !checked;
    generateArp();
}

void MainWindow::on_C_key_pressed()
{
    baseNote = octave * 12;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_Csharp_key_pressed()
{
    baseNote = octave * 12 + 1;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_D_key_pressed()
{
    baseNote = octave * 12 + 2;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_Dsharp_key_pressed()
{
    baseNote = octave * 12 + 3;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_E_key_pressed()
{
    baseNote = octave * 12 + 4;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_F_key_pressed()
{
    baseNote = octave * 12 + 5;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_Fsharp_key_pressed()
{
    baseNote = octave * 12 + 6;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_G_key_pressed()
{
    baseNote = octave * 12 + 7;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_Gsharp_key_pressed()
{
    baseNote = octave * 12 + 8;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_A_key_pressed()
{
    baseNote = octave * 12 + 9;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_Asharp_key_pressed()
{
    baseNote = octave * 12 + 10;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_B_key_pressed()
{
    baseNote = octave * 12 + 11;
    isPlaying = true;
    generateArp();
}

void MainWindow::on_stop_button_pressed()
{
    // stop the stream
    isPlaying = false;
}

void MainWindow::on_arp_type_select_currentIndexChanged(int index)
{
    arp_type = index;
    QApplication::processEvents();
    generateArp();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    octave = arg1;
    baseNote = (octave * 12) + (baseNote % 12);
    generateArp();
}

void MainWindow::on_instrument_select_currentIndexChanged(int index)
{
    patch = index;
    generateArp();
}
