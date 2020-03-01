#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

using namespace CMP33;

QPlainTextEdit* pte = nullptr;
uint32_t timestamp = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pte = ui->plainTextEdit;

    init_midi_in(1);
    init_midi_out(1);
}



void mycallback( double deltatime, std::vector<unsigned char>* message, void* /*userData*/ )
{
    // This is the same callback you wrote for hw621_cmidiin_cmp33
    // to convert message into CMidiPacket data
    // up until you got to std::cout'

      timestamp += deltatime * 1000;

      std::cout << timestamp << '\t' << std::hex << (int)message->at(0) << '\t' << std::dec << (int)message->at(1) << '\t' << std::dec << (int)message->at(2) << std::endl;


    /*
      This is new
      You cannot use std::cout
      You have to use the QPlainTextEdit function insertPlainText.
      Click the Help icon in QtCreator and read about
      QPlainTextEdit
      QString
      Remember the variable pte is a pointer to a QPlainTextEdit widget
      You have to use this
      pte->insertPlainText(const QString &text)
      You've already got a CMidiPacket and you can use mp.to_string();
      Use Qt Help or google to find out how to convert a std::string into a QString.
    */

    // I did it in two lines of code
}

void MainWindow::init_midi_in( uint32_t num )
{
    // copy from c622_rt_cmidiin
    try
    {
       // gmidiin varaiable is in .h class
       // create gmidiin
        gmidiin = new RtMidiIn();
    }

    catch ( RtMidiError& error )
    {
        error.printMessage();
        exit( EXIT_FAILURE );
    }

    gmidiin->openPort( 0 );

    gmidiin->setCallback( &mycallback );
    gmidiin->ignoreTypes( false, false, false );

//    open midiin port( num ); // num is from result of midiprobe.
//    set midiin callback
//    maybe call ignoreTypes
}

void MainWindow::init_midi_out( uint32_t num )
{
    // copy from c623_rt_cmidiout
    try
    {
        gmidiout = new RtMidiOut();
       // gmidiout varaiable is in .h class
       // create gmidiout
    }

    catch ( RtMidiError& error )
    {
        error.printMessage();
        exit( EXIT_FAILURE );
    }


//    open midiout port( num ); // num is from result of midiprobe.
}







MainWindow::~MainWindow()
{
    delete ui;
}

