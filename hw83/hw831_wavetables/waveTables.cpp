#ifndef WAVETABLES_H
#include "waveTables.h"
#endif

#include <QMessageBox>

#include <cmath> // for M_PI
#include <QDebug>

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
    std::vector<MY_TYPE> vout;
    int numSamples = 0;
     size_t L = 0;
     MY_TYPE increment = 0;
     MY_TYPE previous_phase = 0;
     MY_TYPE phaseNow = 0;
     MY_TYPE outsamp = 0;
     MY_TYPE decimalPart = 0;
     unsigned int indxLeft = 0;
     unsigned int indxRight = 0;

     numSamples = std::floor(FS * secs);

//    phaseIndx = 0;
//    MY_TYPE sampleRate = 44100;
//    std::vector<MY_TYPE> vout;
//    MY_TYPE numSamples = sampleRate * secs;
    size_t table_length = wvTbl.size();
//    MY_TYPE T = 1.0/sampleRate;
    MY_TYPE phaseIncr = 1.0* table_length * (freq/FS);


     for(MY_TYPE i = 0; i < numSamples; ++i){
        phaseNow =  std::fmod( indxLeft, L );

        indxLeft = std::floor(phaseNow);

        while (indxLeft >= L) {
            std::fmod( indxLeft, L );
        }

        indxRight = indxLeft + 1;

        while (indxRight >= L) {
            std::fmod( indxLeft, L );
        }

        decimalPart = std::fmod(phaseNow, 1.0);

        outsamp = wvTbl[indxLeft] + (decimalPart * (wvTbl[indxRight] - wvTbl[indxLeft]));
        outsamp = outsamp * amp;

        vout.push_back(outsamp);
        previous_phase = phaseNow;
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
    int x;
    int x0;
    int x1;
    MY_TYPE y;
    MY_TYPE y0;
    MY_TYPE y1;
    MY_TYPE samp;

    for(MY_TYPE i = 0; i < numSamples; ++i){

        x = phaseIndx;
        x0 = floor(phaseIndx);
        x1 = x0 + 1;
        y0 = wvTbl.at(x0 % wvTbl.size());
        y1 = wvTbl.at(x1 % wvTbl.size());
        y = y0 + (x - x0)*( (y1 - y0) / (x1 - x0) );

        while(phaseIndx >= table_length){
            phaseIndx -= table_length;
        }
        samp = amp * y;
        vout.push_back(samp);
        phaseIndx += phaseIncr;
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
