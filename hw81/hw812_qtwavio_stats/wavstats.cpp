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
}

// Utility calculations
MY_TYPE calc_dB( MY_TYPE f1, MY_TYPE f2 )
{
    // you write
    // see class web page
    return 10 * log10(f1 / f2);
}

MY_TYPE getMinSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x = v.at(0);
    for(MY_TYPE i = 0; i < v.size(); i++){
        if(v.at(i) < x){
            x = v.at(i);
        }
    }
    return x;
}

MY_TYPE getMaxSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x = v.at(0);
    for(MY_TYPE i = 0; i < v.size(); i++){
        if(v.at(i) > x){
            x = v.at(i);
        }
    }
    return x;
}

MY_TYPE getRMSamplitude( const std::vector<MY_TYPE>& v )
{
    MY_TYPE mn{0};
    // you write
    // see class web page
    for(MY_TYPE item : v){
        mn += pow(item, 2);
    }
    mn = sqrt((1/v.size()) * mn);
    return mn;
}

// Display calculations
void doCalcNumSamples( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString size;
    size = QString::number(vsamps.size());
    pte->appendPlainText(size);
}

void doCalcLengthSeconds( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString len;
    len = QString::number((vsamps.size() / mysfinfo.channels)  / mysfinfo.samplerate);
    pte->appendPlainText(len);
}

void doCalcDCOffset( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    MY_TYPE one_over_sample_num = 1 / mysfinfo.frames;
    MY_TYPE n = 0;
    for(int i = 0; i < mysfinfo.frames; i++){
        n += vsamps.at(i);
    }
    QString DCOffset;
    DCOffset = QString::number(one_over_sample_num * n);
    pte->appendPlainText(DCOffset);
}

void doCalcMinSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString min_samp;
    min_samp = QString::number(getMinSample(vsamps));
    pte->appendPlainText(min_samp);
}

void doCalcMaxSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString max_samp;
    max_samp = QString::number(getMaxSample(vsamps));
    pte->appendPlainText(max_samp);
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
