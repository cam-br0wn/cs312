#ifndef WAVSTATS_H
#include "wavstats.h"
#endif

#include <QTextStream>

#include <cmath> // for log10
#include <sstream>


SF_INFO mysfinfo;

void displaySF_INFO( QPlainTextEdit* pte )
{
    /*
     * EXAMPLE ONLY
     * More info at
     * https://doc.qt.io/qt-5/qstring.html
     * https://doc.qt.io/qt-5/qtextstream.html
     */

    std::ostringstream oss;
    oss << "SF_INFO frames "<< mysfinfo.frames;
    QString s1(oss.str().c_str());
    pte->appendPlainText( s1 );

    std::ostringstream oss2;
    oss2 << "SF_INFO format "<< std::hex << mysfinfo.format << " hex";
    QString s2(oss2.str().c_str());
    pte->appendPlainText( s2 );

    std::ostringstream data;
    data << "  0x10000 is Microsoft WAV format(little endian)\n";
    data << "   0x0001 is signed 8 bit data\n";
    data << "   0x0002 is signed 16 bit data\n";
    data << "   0x0003 is signed 24 bit data\n";
    data << "   0x0004 is signed 32 bit data\n";
    data << "   0x0005 is unsigned 8 bit data\n";
    data << "   0x0006 is signed 32 bit float data\n";
    data << "   0x0007 is signed 64 bit float data";
    QString datastr(data.str().c_str());
    pte->appendPlainText( datastr );

    std::ostringstream oss3;
    oss3 << "SF_INFO channels "<< mysfinfo.channels;
    QString s3(oss3.str().c_str());
    pte->appendPlainText( s3 );

    std::ostringstream oss4;
    oss4 << "SF_INFO samplerate "<< mysfinfo.samplerate;
    QString s4(oss4.str().c_str());
    pte->appendPlainText( s4 );

//    int samplerate = 44100;
//    QString s4 = QString( "s4 samplerate = %1" ).arg( samplerate );
//    pte->appendPlainText( s4 );

//    double k2PI = 6.2831853;
//    QString s5 = QString( "s5 k2PI = %1" ).arg( k2PI, 0, 'f', 6 );
//    pte->appendPlainText( s5 );

//    int num = 65536;
//    QString s6 = QString( "s5 65536 is %1 hex " ).arg( num, 0, 16 );
//    pte->appendPlainText( s6 );

//    std::ostringstream oss;
//    oss << "s7\tnRead = " << nRead << "\n\tvsize = " << vsize << "\n\tsamplerate = " << samplerate;
//    QString s7( oss.str().c_str() );
//    pte->appendPlainText( s7 );
}

// Utility calculations
MY_TYPE calc_dB( MY_TYPE f1, MY_TYPE f2 )
{
    // you write
    // see class web page
}

MY_TYPE getMinSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x{0};
    // you write
    // see class web page
    return x;
}

MY_TYPE getMaxSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x{0};
    // you write
    // see class web page
    return x;
}

MY_TYPE getRMSamplitude( const std::vector<MY_TYPE>& v )
{
    MY_TYPE mn{0};
    // you write
    // see class web page
    return mn;
}

// Display calculations
void doCalcNumSamples( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcLengthSeconds( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcDCOffset( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcMinSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcMaxSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcMaxSample_dB( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcRMSAmplitude( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCalcPeakCount( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void doCountClipping( QPlainTextEdit* pte )
{
    // you write
    // see class web page
}

void displayStats( QPlainTextEdit* pte )
{
    doCalcNumSamples( pte );
    doCalcLengthSeconds( pte );
    doCalcDCOffset( pte );
    doCalcMinSample( pte );
    doCalcMaxSample( pte );
    doCalcMaxSample_dB( pte );
    doCalcRMSAmplitude( pte );
    doCalcPeakCount( pte );
    doCountClipping( pte );
}
