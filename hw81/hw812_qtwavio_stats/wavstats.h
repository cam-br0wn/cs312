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

const int FS = 44100;

extern std::vector<double> vsamps;

extern void displaySF_INFO( QPlainTextEdit* pte );
extern void displayStats( QPlainTextEdit* pte );

#endif //
