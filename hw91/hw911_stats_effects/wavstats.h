#ifndef WAVSTATS_H
#define WAVSTATS_H

#ifndef SNDFILE_HH
#include "sndfile.hh"
#endif

#ifndef WAVIO_H
#include "wavio.h"
#endif

#include <QPlainTextEdit>
#include <QString>

#include <vector>

typedef double MY_TYPE;
#define FORMAT RTAUDIO_FLOAT64

//const int FS = 44100;

extern std::vector<double> vsamps;

// stats functions
extern MY_TYPE calc_dB( MY_TYPE f1, MY_TYPE f2 );
extern MY_TYPE getMaxSample( const std::vector<MY_TYPE>& v );
extern MY_TYPE getPeakdB( const std::vector<MY_TYPE>& v );
extern MY_TYPE getDCoffset( const std::vector<MY_TYPE>& v );

extern void displaySF_INFO( QPlainTextEdit* pte );
extern void displayStats( QPlainTextEdit* pte );

#endif // WAVSTATS_H
