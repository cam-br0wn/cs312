#ifndef RTAUDIOUTILS_H_
#define RTAUDIOUTILS_H_
#endif

#ifndef __RTAUDIO_H
#include "RtAudio.h"
#endif

#include <cmath> // for M_PI

// double required for hw82 - hw92
typedef double MY_TYPE;
#define FORMAT RTAUDIO_FLOAT64

const int FS = 44100;
const MY_TYPE k2PI = 2 * M_PI;
const MY_TYPE T = 1.0 / FS; // sample period
const MY_TYPE k2PIT = k2PI * T;
const unsigned int kRTABUFFER_SZ = 512;
const unsigned int callbackReturnValue = 1;

extern RtAudio::StreamOptions options;
extern RtAudio::StreamParameters oParams;

struct RTA
{
    // RtAudio stuff
    unsigned int channels;
    unsigned int frameCounter;
    bool checkCount;
    unsigned int nFrames;
    unsigned int bufferFrames;
    unsigned int fs;
    unsigned int device;
    unsigned int offset;

    // constructor
    RTA();
};

extern RTA rta; // declared here, defined in rtaudioutils.cpp
extern void errorCallback( RtAudioError::Type type, const std::string& errorText );
