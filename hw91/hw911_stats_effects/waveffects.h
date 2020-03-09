#ifndef WAVEFFECTS_H
#define WAVEFFECTS_H

#ifndef WAVIO_H
#include "wavio.h" // for MY_TYPE
#endif

#include <QLabel>

extern MY_TYPE normalize_dBval;
extern MY_TYPE changeSpeed_rate;
extern MY_TYPE amplify_maxSample;
extern int echo_num;
extern MY_TYPE echo_delay;
extern MY_TYPE echo_damp;

extern int snip_minLen;
extern int snip_maxLen;
extern int snip_reps;

extern std::vector<MY_TYPE> veffect;

void doRemoveDC();
void doNormalize( MY_TYPE val );
void doAmplify( MY_TYPE val );
void doReverse();
void doEchos();
void doChangeSpeed( MY_TYPE rate );
void doRandomSnips( QLabel* label );

#endif // WAVEFFECTS_H
