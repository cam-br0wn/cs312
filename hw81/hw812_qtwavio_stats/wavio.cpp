#ifndef WAVIO_H
#include "wavio.h"
#endif

#include <QDebug>


void doMessageBox( const QString& qs )
{
    QMessageBox msgBox;
    msgBox.setText( qs );
    msgBox.exec();
}

std::vector<MY_TYPE> readWav( std::string path )
{
    // Create SndfileHandle class variable named infile initialized with the parameter path

    SndfileHandle file;

    file = SndfileHandle(path);


    unsigned long long int numSamples = file.frames();

    // get the number of samples in the file and create a vector of that size
    std::vector<double> v(numSamples);

    // read samples into v and report the number read in nRead
    // a valid read would report frames == nRead
     sf_count_t nRead = file.read( &v[ 0 ], file.frames() );

    // Display the results in the Application Output panel
    // finish each fo the following lines with the appropriate SndfileHandle
    //  function to display that particular information

     mysfinfo.frames = file.frames();
     mysfinfo.format = file.format();
     mysfinfo.channels= file.channels();
     mysfinfo.samplerate = file.samplerate();

     qDebug() << QString::fromStdString(path);
     qDebug() << "frames " << file.frames();
     qDebug() << "format " << file.format() ;
     qDebug() << "channels " << file.channels() ;
     qDebug() << "samplerate " << file.samplerate();
     qDebug() << "nRead " << nRead;

     vsamps = v;

    return v;
}

void writeWav( std::string fname, const std::vector<MY_TYPE>& v )
{

    SndfileHandle file;
    file = SndfileHandle(fname);

    doMessageBox( "You need to implement writeWav(...) in wavio.cpp" );

    // from libsndfile example sndfile.hh
    /*
      These are the parameters you'll need for creating a SndfileHandle
      use the constructor shown in the web page notes parameters follow
        path = fname
        mode = SFM_WRITE
        format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE
        channels = 1
        samplerate = 44100

      declare and initialize variable: nWritten
      create the SndfileHandle outfile = SndfileHandle( fname, mode, format, channels, samplerate );
      declare and initialize variable: sz is equal to size of vsamps vector set in readSF()
      call nWritten = outfile.write( &vsamps[ 0 ], sz );
    */

    std::string path = fname;
    int mode = SFM_WRITE;
    int format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
    int channels = 1;
    int samplerate = 44100;
    sf_count_t nWritten;
    SndfileHandle outfile = SndfileHandle(fname, mode, format, channels, samplerate);
    unsigned long sz = v.size();
    nWritten = outfile.write( &v[0], sz);

}
