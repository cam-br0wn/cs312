#ifndef GLOBALS_H_
#define GLOBALS_H_
#endif

#include <vector>

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h" // for MY_TYPE
#endif

extern bool isSine;
extern bool isSquare;
extern bool isSawUp;
extern bool isSawDown;
extern bool isTriangle;
extern bool isPlaying;

enum eWaveType
{
    esine,
    esquare,
    esawup,
    esawdown,
    etriangle
};
extern eWaveType ewave;

extern int hSlider_numHarmonics;
extern MY_TYPE hSlider_freq;
extern MY_TYPE hSlider_ampl;
extern MY_TYPE plot_buffer[ kRTABUFFER_SZ ];
extern RtAudio dac;
extern std::vector<MY_TYPE> vsamps;
