/***************************************************************
hw723_gensin_beatDemo.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw723
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-2-24
TIME: 14:50:25
****************************************************************/

#include "sndfile.hh"
#include <iostream>
#include <vector>
#include <cmath> // for M_PI

// either_or
typedef float MY_TYPE;
#define LIB_SF_FORMAT SF_FORMAT_FLOAT; // SF_FORMAT_MY_TYPE defiend in  "sndfile.h"
// typedef double MY_TYPE;
// #define LIB_SF_FORMAT SF_FORMAT_DOUBLE; // SF_FORMAT_MY_TYPE defiend in  "sndfile.h"
// END either_or

const int FS = 44100;       // CD sample rate
const MY_TYPE T = 1.0 / FS; // sample period
const MY_TYPE k2PI = M_PI * 2.0;
const MY_TYPE k2PIT = k2PI * T;

std::vector<MY_TYPE> gen_sin_phasor(MY_TYPE freq, MY_TYPE ampl, MY_TYPE secs)
{
    std::vector<MY_TYPE> v;
    // std::cout << "You need to implement gen_sin_phasor(...)\n";

    MY_TYPE phzNow;
    MY_TYPE phzIncr;
    phzNow = 0;
    phzIncr = k2PIT * freq;
    for (int n = 0; n < FS * secs; n++)
    {
        v.push_back(ampl * sin(phzNow));
        phzNow += phzIncr;
        if (phzNow > k2PI)
        {
            phzNow = phzNow - k2PI;
        }
    }
    /*----------------------------------------------------
     declare variable MY_TYPE phzNow
     declare variable MY_TYPE phzIncr
     set phzNow to zero
     calculate the phase increment in radians for freq
     BEGIN_LOOP from 0 to number of samples in secs paramater
     push ampl*sin(phzNow) to vector v
     increment phzNow
     check if phzNow greater than 2pi
     if so wrap around (phzNow = phzNow - 2pi)
     END_LOOP
     ----------------------------------------------------*/
    return v;
}

bool samples2wavfile(const char *fname, const std::vector<MY_TYPE> &v)
{
    // code borrowed and modified from libsndfile example sndfilehandle.cc
    // mostly from create_file(...) and format from main()
    SndfileHandle file;
    const int channels = 1;
    const int srate = FS;
    const int format = SF_FORMAT_WAV | LIB_SF_FORMAT;

    file = SndfileHandle(fname, SFM_WRITE, format, channels, srate);

    // using vector instead of buffer array
    // C++ vector elements are stored in contiguous memory, same as array
    // &v[0] is pointer to first element of vector
    file.write(&v[0], v.size());
    return true;
}

int main(int argc, char *argv[])
{
    // beats
    std::vector<MY_TYPE> v1 = gen_sin_phasor(220.0, 0.5, 5.0); // note the sum of the two amplitudes are <= 1.0
    std::vector<MY_TYPE> v2 = gen_sin_phasor(220.5, 0.5, 5.0);
    std::vector<MY_TYPE> vout;
    for (auto n = 0; n != v1.size(); ++n)
        vout.push_back(v1.at(n) + v2.at(n));
    samples2wavfile("hw723_a220sine_beats.wav", vout);

    // reset for no beats
    v1 = gen_sin_phasor(220.0, 0.5, 2.5); // note the sum of the two amplitudes are <= 1.0
    v2 = gen_sin_phasor(220.5, 0.5, 2.5);
    vout.clear();
    for (auto n = 0; n != v1.size(); ++n)
        vout.push_back(v1.at(n) + v2.at(n));
    samples2wavfile("hw723_a220sine_nobeats.wav", vout);

    return 0;
}
