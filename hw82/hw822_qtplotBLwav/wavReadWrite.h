#ifndef WAVEREADWRITE_H_
#define WAVEREADWRITE_H_

#ifndef SNDFILE_HH
#include "sndfile.hh"
#endif

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

#include <string>
#include <vector>

#include <QString>

extern std::vector<MY_TYPE> readWav( std::string fname );
extern void writeWav( std::string fname, const std::vector<MY_TYPE>& vin );

#endif // WAVEREADWRITE_H_
