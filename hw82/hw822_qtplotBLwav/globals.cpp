#ifndef GLOBALS_H_
#include "globals.h"
#endif

bool isSine{false};
bool isSquare{false};
bool isSawUp{false};
bool isSawDown{false};
bool isTriangle{false};
bool isPlaying = false;

eWaveType ewave = esine;

int hSlider_numHarmonics{3};
MY_TYPE hSlider_freq{440};
MY_TYPE hSlider_ampl{0.75};
MY_TYPE plot_buffer[ kRTABUFFER_SZ ];
RtAudio dac;
std::vector<MY_TYPE> vsamps;
