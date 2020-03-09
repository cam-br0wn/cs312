#ifndef WAVIO_H
#include "wavio.h"
#endif

SF_INFO mysfinfo;

void doMessageBox( const QString& qs )
{
    QMessageBox msgBox;
    msgBox.setText( qs );
    msgBox.exec();
}

std::vector<MY_TYPE> readWav( std::string fname )
{
    sf_count_t nRead{0};
    SndfileHandle infile = SndfileHandle( fname );
    sf_count_t frames = infile.frames();
    std::vector<double> v( static_cast<unsigned long>( frames ) );
    nRead = infile.read( &v[ 0 ], frames );

    mysfinfo.frames = infile.frames();
    mysfinfo.format = infile.format();
    mysfinfo.channels = infile.channels();
    mysfinfo.samplerate = infile.samplerate();

    return v;
}

void writeWav( std::string fname, const std::vector<MY_TYPE>& v )
{
    // from libsndfile example sndfile.hh
    const int chan = 1;
    const int srate = 44100;
    const int mode = SFM_WRITE;
    const int format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;

    sf_count_t numWritten{0};
    SndfileHandle outfile = SndfileHandle( fname, mode, format, chan, srate );

    // C++ vector elements are stored in contiguous memory, same as memory buffer
    // &v[0] is pointer to first element of vector
    sf_count_t sz = static_cast<long long>( v.size() );
    numWritten = outfile.write( &v[ 0 ], sz );
}
