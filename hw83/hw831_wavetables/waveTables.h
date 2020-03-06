#ifndef WAVETABLES_H
#define WAVETABLES_H

#ifndef SNDFILE_HH
#include "sndfile.hh"
#endif

#include <QString>

#include <string>
#include <vector>

// double required for QCustomPlot
typedef double MY_TYPE;
#define FORMAT RTAUDIO_FLOAT64

const int FS = 44100;
extern std::vector<MY_TYPE> create_wavetable( int table_sz );

extern void doMessageBox( const QString& qs );
extern std::vector<MY_TYPE> truncateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs );
extern std::vector<MY_TYPE> roundWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs );
extern std::vector<MY_TYPE> interpolateWavetable( std::vector<MY_TYPE> wvTbl, MY_TYPE amp, MY_TYPE freq, MY_TYPE secs );

extern void writeWav( std::string fname, const std::vector<MY_TYPE>& vin );

#endif // WAVETABLES_H
