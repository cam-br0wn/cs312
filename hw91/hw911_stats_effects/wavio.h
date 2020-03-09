#ifndef WAVIO_H
#define WAVIO_H

#ifndef SNDFILE_HH
#include "sndfile.hh"
#endif

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

#include <string>
#include <vector>

#include <QMessageBox>
#include <QString>

extern SF_INFO mysfinfo;

extern void doMessageBox( const QString& qs );
extern std::vector<MY_TYPE> readWav( std::string fname );
extern void writeWav( std::string fname, const std::vector<MY_TYPE>& vin );

#endif // WAVIO_H
