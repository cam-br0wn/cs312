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
    phaseIndx = 0;
    MY_TYPE sampleRate = 44100;
    std::vector<MY_TYPE> vout;
    MY_TYPE numSamples = sampleRate * secs;
    size_t table_length = wvTbl.size();
    MY_TYPE phaseIncr = table_length * freq * (1.0 / sampleRate);
    int tableIndx;
    MY_TYPE samp;

    for(MY_TYPE i = 0; i < numSamples; ++i){
        tableIndx = std::floor(phaseIndx);
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
    MY_TYPE phaseIncr = table_length * freq * (1.0 / sampleRate);
    int tableIndx;
    MY_TYPE samp;

    for(MY_TYPE i = 0; i < numSamples; ++i){
        tableIndx = std::round(phaseIndx);
        while(tableIndx >= table_length){
            tableIndx -= table_length;
        }
        samp = amp * wvTbl.at(tableIndx);
        vout.push_back(samp);
        phaseIndx += phaseIncr;
    }
    return vout;
}
/*
std::vector<MY_TYPE> interpolateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs )
{

    // y(i,ß) = S[i] + ß(S[i+1] - S[i])
    // given wavetable S, sample y at table address i and fraction address ß equals S[i] + ß(S[s+1] - S[i]) if we're linearly interpolating

    std::vector<MY_TYPE> vout;
    MY_TYPE samp;

    MY_TYPE sample_rate = 44100;
    MY_TYPE num_samples = sample_rate * secs;
    MY_TYPE phase_index = 0;

    unsigned long table_length = wvTbl.size();
    MY_TYPE T = 1.0 / sample_rate;
    MY_TYPE phase_increment = table_length * freq * T;

    MY_TYPE table_index_prev; // i
    MY_TYPE table_index_next; // i + 1

    MY_TYPE sample_value_prev; // S[i]
    MY_TYPE sample_value_next; // S[i+1]

    for(int i = 0; i < num_samples; i++){

        if(phase_index >= table_length){
            phase_index -= table_length;
        }

        table_index_prev = floor(phase_index);
        table_index_next = table_index_prev + 1;

        sample_value_prev = wvTbl.at(table_index_prev);
        sample_value_next = wvTbl.at(table_index_next);

        MY_TYPE ß = phase_index - table_index_prev;

        samp = sample_value_prev + (ß * (sample_value_next - sample_value_prev));
        vout.push_back(amp * samp);

        phase_index += phase_increment;

    }

    return vout;
}
*/

std::vector<MY_TYPE> interpolateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs ){
    /*
    declare variables
        std::vector<MY_TYPE> vout

        Initialize these variables to zero
        int numSamples
        size_t L
        MY_TYPE increment
        MY_TYPE previous_phase
        MY_TYPE phaseNow
        MY_TYPE outsamp
        MY_TYPE decimalPart
        unsigned int indxLeft
        unsigned int indxRight

    calc numSamples based on std::floor (FS*secs)
    calc L = wvTbl size
    calc increment using wavetable formula
    increment = 1.0 * L * freq/FS

    for loop from 0 to numSamples
    calc phaseNow as
      phaseNow = std::fmod( previous_phase + increment, L );

    set indxLeft to std::floor of phaseNow
    while indxLeft >= L calc indxLeft mod L

     indxRight = indxLeft + 1
    while indxRight >= L calc indxLeft mod L

    calc the decimal part of phaseNow
    you can use
    decimalPart = std::fmod(phaseNow, 1.0)
    or
    decimalPart = phaseNow - std::floor(phaseNow)

    calculate the interpolated sample
    outsamp = wavTbl[indxLeft] + (decimalPart * (wavTable[indxRight] - wavTable[indxLeft]))

    multiply outsamp by amp
    push_back outsamp
    set previous_phase = phaseNow
    end for loop

    return vout
    */

    std::vector<MY_TYPE> vout;

    int num_samples{0};
    size_t L{0};
    MY_TYPE increment{0};
    MY_TYPE previous_phase{0};
    MY_TYPE phase_now{0};
    MY_TYPE outsamp{0};
    MY_TYPE decimal_part{0};
    unsigned int index_left{0};
    unsigned int index_right{0};

    num_samples = std::floor(secs * 44100);
    L = wvTbl.size();
    increment = L * freq * (1.0 / 44100);

    for(int s = 0; s < num_samples; s++){
        phase_now = std::fmod(previous_phase + increment, L);
        index_left = std::floor(phase_now);
        while(index_left >= L){
            index_left = std::fmod(index_left, L);
        }
        index_right = index_left + 1;
        while(index_right >= L){
            index_right = std::fmod(index_right, L);
        }
        decimal_part = std::fmod(phase_now, 1.0);
        outsamp = wvTbl[index_left] + (decimal_part * (wvTbl[index_right] - wvTbl[index_left]));
        outsamp = outsamp * amp;
        vout.push_back(outsamp);
        previous_phase = phase_now;
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
