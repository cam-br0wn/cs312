#ifndef WAVIO_H
#define WAVIO_H

#ifndef SNDFILE_HH
#include "sndfile.hh"
#endif

#include <string>
#include <vector>

#include <QMessageBox>
#include <QString>

typedef double MY_TYPE;
#define FORMAT RTAUDIO_FLOAT64

static std::vector<double> vsamps;
extern SF_INFO mysfinfo;

extern void doMessageBox( const QString& qs );
extern std::vector<MY_TYPE> readWav( std::string fname );
extern void writeWav( std::string fname, const std::vector<MY_TYPE>& vin );

#endif // WAVIO_H
