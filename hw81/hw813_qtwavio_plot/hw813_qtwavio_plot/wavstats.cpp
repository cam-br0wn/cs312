#ifndef WAVSTATS_H
#include "wavstats.h"
#endif

#include <QTextStream>

#include <cmath> // for log10
#include <sstream>

#include <QDebug>


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
   const MY_TYPE vref = 1.0;
   f2 = vref;
   return 20 * log10(abs(f1) / f2);
}

MY_TYPE getMinSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x{0};
    for(MY_TYPE i = 0; i < v.size(); i++){
        if(v.at(i) < x){
            x = v.at(i);
        }
    }
    return x;
}

MY_TYPE getMaxSample( const std::vector<MY_TYPE>& v )
{
    MY_TYPE x{0};
    for(MY_TYPE i = 0; i < v.size(); i++){
        if(std::abs(v.at(i)) > x){
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
    mn = sqrt((1.0/v.size()) * mn);
    return mn;
}

// Display calculations
void doCalcNumSamples( QPlainTextEdit* pte )
{
    int size = vsamps.size();
    QString s4 = QString( "Samples = %1" ).arg( size );
    pte->appendPlainText( s4 );
}

void doCalcLengthSeconds( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString len;
    len = QString::number((vsamps.size() / (mysfinfo.channels * 1.0))  / mysfinfo.samplerate);
    pte->appendPlainText(QString("Length s: ") + len);
}

void doCalcDCOffset( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    MY_TYPE one_over_sample_num = 1.0 / mysfinfo.frames;
    MY_TYPE n = 0;
    for(int i = 0; i < mysfinfo.frames; i++){
        n += vsamps.at(i);
    }
    QString DCOffset;
    DCOffset = QString::number(one_over_sample_num * n);
    pte->appendPlainText(QString("DC Offset: ") + DCOffset);
}

void doCalcMinSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString min_samp;
    min_samp = QString::number(getMinSample(vsamps));
    pte->appendPlainText(QString("Min level: ") + min_samp);
}

void doCalcMaxSample( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString max_samp;
    max_samp = QString::number(getMaxSample(vsamps));
    pte->appendPlainText(QString("Max level: ") + max_samp);
}

void doCalcMaxSample_dB( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString max_samp_dB;
    max_samp_dB = QString::number(calc_dB(getMaxSample(vsamps), 1));
    pte->appendPlainText(QString("Peak level dB: ") + max_samp_dB);
}

void doCalcRMSAmplitude( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    QString RMS_amp;
    RMS_amp = QString::number(getRMSamplitude(vsamps));
    pte->appendPlainText(QString("RMS Amplitude: ") + RMS_amp);
}

void doCalcPeakCount( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    // samples @ max sample
    MY_TYPE peaks = 0;
    MY_TYPE peak_max = getMaxSample(vsamps);
    MY_TYPE peak_min = getMinSample(vsamps);
    for(int i = 0; i < mysfinfo.frames; i++){
        MY_TYPE samp = vsamps.at(i);
        if(samp == peak_max || samp == peak_min){
            peaks++;
        }
    }
    QString num_peaks;
    num_peaks = QString::number(peaks);
    pte->appendPlainText(QString("Peak count: ") + num_peaks);
}

void doCountClipping( QPlainTextEdit* pte )
{
    // you write
    // see class web page
    // exceed 1.0 or -1.0
    MY_TYPE clips = 0;
    const MY_TYPE clip_upper = 1.0;
    const MY_TYPE clip_lower = -1.0;
    for(int i = 0; i < mysfinfo.frames; i++){
        MY_TYPE samp = vsamps.at(i);
        if(samp > clip_upper || samp < clip_lower){
            clips++;
        }
    }
    QString num_clips;
    num_clips = QString::number(clips);
    pte->appendPlainText(QString("Clipped samples: ") + num_clips);
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
