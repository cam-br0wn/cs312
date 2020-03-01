/***************************************************************
hw726_gensin_fmmod.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw726
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-2-24
TIME: 14:46:25
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
    MY_TYPE phzNow = 0;
    MY_TYPE phzIncr = k2PIT * freq;
    for (int n = 0; n < secs * FS; n++)
    {
        v.push_back(ampl * sin(phzNow));
        phzNow += phzIncr;
        // wrap around 2pi
        if (phzNow > k2PI)
            phzNow -= k2PI;
    }
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

std::vector<MY_TYPE> fm_modulation(MY_TYPE A, MY_TYPE Fc, MY_TYPE Fm, MY_TYPE dFm, MY_TYPE secs)
{
    // Function Parameters
    // A:     amplitude
    // Fc:    carrierFrequency
    // Fm:    modulationFrequency
    // secs:  duration in floating point seconds
    // dFm:   deltaFm

    // Variables/constants needed
    // samp:  a single sample value
    // n:     sample number as in samp[n]
    // Fs:    sampling frequency 44100
    // T:     sampling period 1/FS
    // I:     modulationIndex

    std::vector<MY_TYPE> vout;
    /*---------------------------------------------------
   implement the FM formula on the class web page
   carF = 2*pi*Fc*T is a constant that can be pre-calculated outside of the loop
   carM = 2*pi*Fm*T is a constant that can be pre-calculated outside of the loop

  loop for samples 0 to total number of samples
       samp = A * sin( carF * n + I* sin( carM * n ) );
       vout.push_back(samp);
  end loop
  ----------------------------------------------------*/
    MY_TYPE carF = k2PIT * Fc;
    MY_TYPE carM = k2PIT * Fm;
    for (int n = 0; n < FS * secs; n++)
    {
        vout.push_back(A * sin(carF * n + (dFm / Fm) * sin(carM * n)));
    }
    // std::cout << "You need to implement fm_modulation(...)\n";
    return vout;
}

void write_fm_file(const std::string &fname, const std::vector<MY_TYPE> &v)
{
    if (!samples2wavfile(fname.c_str(), v))
        std::cout << fname << std::endl;
}

int main(int argc, char *argv[])
{
    // DO NOT MODIFY
    /*--------------------------------------------------
      Chowning examples without Envelopes
      Parameters on class web page
      Chowning used A=1000 (amplitude) but did not indicate units
      Test with one example at a time until you get all to work
      Compare your results with mp3 files on web page.
    --------------------------------------------------*/
    MY_TYPE A = 1.0;
    std::vector<MY_TYPE> vout = fm_modulation(A, 100, 100, 400, 1.5);
    write_fm_file("Example1.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(A, 440, 440, 2200, 1.5);
    //  write_fm_file("Example2.wav", vout);

    //  vout = fm_modulation(A, 900, 300, 600, 1.5);
    //  write_fm_file("Example3a.wav", vout);

    //  vout = fm_modulation(A, 500, 100, 150, 1.5);
    //  write_fm_file("Example3b.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(A, 900, 600, 2400, 1.5);
    //  write_fm_file("Example3c.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(A, 200, 280, 2800, 6);
    //  write_fm_file("Example4a.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(A, 200, 280, 560, 0.2);
    //  write_fm_file("Example4b.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(A, 80, 55, 375, 2.0);
    //  write_fm_file("Example4c.wav", vout);

    /*--------------------------------------------------
      JE examples
    --------------------------------------------------*/
    //  vout.clear();
    //  vout = fm_modulation(0.75, 549, 387, 300, 1.5);
    //  write_fm_file("hw725_fm_bell.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(0.75, 440, 3.0, 3.0, 3.0);
    //  write_fm_file("hw725_fm_vibrato.wav", vout);

    //  vout.clear();
    //  vout = fm_modulation(0.75, 440, 10, 10 * 20, 2.0);
    //  write_fm_file("hw725_fm_raygun.wav", vout);

    /*--------------------------------------------------
     Create four of your own fm modulation examples below
    --------------------------------------------------*/

    return 0;
}