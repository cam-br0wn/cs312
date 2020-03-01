/***************************************************************
hw721_gensin.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw721
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
const MY_TYPE k2PI = 2 * M_PI;
const MY_TYPE k2PIT = k2PI * T;

std::vector<MY_TYPE> gen_sin(MY_TYPE freq, MY_TYPE ampl, MY_TYPE secs)
{
  std::vector<MY_TYPE> v;
  // std::cout << "You need to implement gen_sin(...)\n";
  for (int n = 0; n < FS * secs; n++)
  {
    v.push_back(ampl * sin(k2PIT * freq * n));
  }
  /*----------------------------------------------------
    // FORMULA: samp(n) = A * sin( 2 * pi * freq * n * T);
    // calculute 2*pi*T outside of the for loop for efficiency
    // FORMULA: samp(n) = A * sin( k2PIT* freq * n);
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
  // generate a 440 Hz, full 1.0 amplitude sine wave for one second
  std::vector<MY_TYPE> vsamps = gen_sin(440.0, 1.0, 1.0);
  samples2wavfile("hw721_a440sine_amp1.wav", vsamps);

  // generate a 440 Hz, half 0.5 amplitude sine wave for one second
  vsamps.clear();
  vsamps = gen_sin(440.0, 0.5, 1.0);
  samples2wavfile("hw721_a440sine_amp1half.wav", vsamps);

  return 0;
}