#ifndef BANDLIMITEDWAVS_H
#define BANDLIMITEDWAVS_H

#ifndef GLOBALS_H_
#include "globals.h"
#endif

#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

extern void doSineCallback( unsigned int nBufferFrames, MY_TYPE* buffer );
extern void doPlotSine();

extern void doSquareBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer );
extern void doPlotSquareBL();

extern void doSawUpBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer );
extern void doPlotSawUpBL();

extern void doSawDownBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer );
extern void doPlotSawDownBL();

extern void doTriangleBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer );
extern void doPlotTriangleBL();

#endif // BANDLIMITEDWAVS_H
