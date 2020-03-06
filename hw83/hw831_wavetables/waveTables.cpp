#ifndef WAVETABLES_H
#include "waveTables.h"
#endif

#include <QMessageBox>

#include <cmath> // for M_PI

static MY_TYPE phaseIndx{0};

std::vector<MY_TYPE> create_wavetable( int table_sz )
{
    /*
        declare const for frequency of 1.0 Hz
        declare vector for return value
        declare variable for 1.0/table_sz
        declare variable for single sample of MY_TYPE

        loop for n=0 to table_sz
            samp = sin(2*pi*f*kOneHz*n*OneOverTableSize)
            push_back(samp)
        end-loop

        return vector
    */
    const double kOneHz = 1.0;
    std::vector<MY_TYPE> v;
    double OneOverTableSize = 1.0/table_sz;
    MY_TYPE single_samp;

    for(int n = 0; n < table_sz; ++n){
        single_samp = sin(2 * M_PI * kOneHz * n * OneOverTableSize); // where does the 'f' term come from?
        v.push_back(single_samp);
    }

    return v;
}

void doMessageBox( const QString& qs )
{
    QMessageBox msgBox;
    msgBox.setText( qs );
    msgBox.exec();
}

std::vector<MY_TYPE> truncateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs )
{
    /*
  set static file scope variable phaseIndx to zero
    declare vector vout for return value
    declare variable numSamples for number of samples needed based on sampleRate * seconds
    declare variable table_length for wvTbl size
    declare variable T for 1.0/sampleRate
    declare variable phaseIncr for phase_increment MY_TYPE (see web page)
    declare variable tableIndx for wvTble index  integer type
    declare variable samp for single sample MY_TYPE

    loop through number of samples needed
        set tableIndx to floor of phaseIndx
        while tableIndex is >= table_length
            tableIndex subtract table_length
        samp equals amp * wvTable at index tableIndx
        push_back samp
        add phaseIncr to phaseIndx
    end-loop

    HINT:
    use qDebug() << phaseIndx << << " " << tableIndx
    to observe these variables in the Application Output
  panel at the bottom of QtCreator.

    return vout
*/
    //    doMessageBox( "You need to implement truncateWavetable()" );
    phaseIndx = 0;
    MY_TYPE sampleRate = 44100;
    std::vector<MY_TYPE> vout;
    MY_TYPE numSamples = sampleRate * secs;
    size_t table_length = wvTbl.size();
    MY_TYPE T = 1.0/sampleRate;
    MY_TYPE phaseIncr = 2 * M_PI * freq * T;
    int tableIndx;
    MY_TYPE samp;

    for(MY_TYPE i = 0; i < numSamples; ++i){
        tableIndx = floor(phaseIndx);
        while(tableIndx >= table_length){
            tableIndx -= table_length;
        }
        samp = amp * wvTbl.at(tableIndx);
        vout.push_back(samp);
        phaseIndx += phaseIncr;
    }
    return vout;
}

std::vector<MY_TYPE> roundWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs )
{
    phaseIndx = 0;
    MY_TYPE sampleRate = 44100;
    std::vector<MY_TYPE> vout;
    MY_TYPE numSamples = sampleRate * secs;
    size_t table_length = wvTbl.size();
    MY_TYPE T = 1.0/sampleRate;
    MY_TYPE phaseIncr = 2 * M_PI * freq * T;
    int tableIndx;
    MY_TYPE samp;

    for(MY_TYPE i = 0; i < numSamples; ++i){
        tableIndx = round(phaseIndx);
        while(tableIndx >= table_length){
            tableIndx -= table_length;
        }
        samp = amp * wvTbl.at(tableIndx);
        vout.push_back(samp);
        phaseIndx += phaseIncr;
    }
    return vout;
}

std::vector<MY_TYPE> interpolateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs )
{
    phaseIndx = 0;
    MY_TYPE sampleRate = 44100;
    std::vector<MY_TYPE> vout;
    MY_TYPE numSamples = sampleRate * secs;
    size_t table_length = wvTbl.size();
    MY_TYPE T = 1.0/sampleRate;
    MY_TYPE phaseIncr = 2 * M_PI * freq * T;
    int tableIndx;
    MY_TYPE samp;
    vout.push_back(amp * wvTbl.at(0));
    for(MY_TYPE i = 1.0; i < numSamples - 1.0; ++i){
        vout.push_back(amp * (wvTbl.at(i-1) + ((i - (i-1))*((wvTbl.at(i+1) - wvTbl.at(i-1))/((i + 1) - (i - 1))))));
    }
    return vout;
}

void writeWav( std::string fname, const std::vector<MY_TYPE>& v )
{
    SndfileHandle file;
    file = SndfileHandle(fname);
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
