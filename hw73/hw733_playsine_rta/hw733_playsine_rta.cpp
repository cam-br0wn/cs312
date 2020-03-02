// REPLACE ABOVE with
/******************************************/
/*
 playsaw.cpp
 by Gary P. Scavone, 2006
 Modified for hw732_playsine.cpp
 John Ellinger CS312
*/
/******************************************/
#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

#include <cmath> // for M_PI



// REPLACE ABOVE with
// One-channel sine wave generator replaces saw callback function
int sine(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
 double streamTime, RtAudioStreamStatus status, void *userData)
{
 MY_TYPE *buffer = (MY_TYPE *)outputBuffer;
 if (status)
 std::cout << "Stream underflow detected!" << std::endl;
 static MY_TYPE phz = 0;
 MY_TYPE freq = 440.0;
 MY_TYPE amp = 1.0;
 // //phase increment formula
 const MY_TYPE phzinc = k2PIT * freq;
 for (uint32_t i = 0; i < nBufferFrames; i++)
 {
 *buffer++ = amp * sin(phz);
 phz += phzinc;
 if (phz >= k2PI)
 phz -= k2PI;
 }
 rta.frameCounter += nBufferFrames;
 if (rta.checkCount && (rta.frameCounter >= rta.nFrames))
 return callbackReturnValue;
 return 0;
}

// int sineSweep(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
//          double streamTime, RtAudioStreamStatus status, void *userData)
// {
//   MY_TYPE *buffer = (MY_TYPE *)outputBuffer;
//   if (status)
//     std::cout << "Stream underflow detected!" << std::endl;
//   MY_TYPE freq = 440.0;
//   MY_TYPE amp = 1.0;
//   static MY_TYPE phz = 0; // must be static
//   MY_TYPE phzinc = k2PIT * freq;
//   // add a new static variable that retains its value across multiple callbacks
//   static MY_TYPE tmpfreq{freq};

//   // //phase increment formula
//   for (uint32_t i = 0; i < nBufferFrames; i++)
//   {
//     phzinc = k2PIT * (freq + tmpfreq);
//     tmpfreq += 0.01;
//     if (tmpfreq > freq * 3)
//       tmpfreq = freq;
//     *buffer++ = amp * sin(phz);
//     phz += phzinc;
//     if (phz >= k2PI)
//       phz -= k2PI;
//   }
//   rta.frameCounter += nBufferFrames;
//   if (rta.checkCount && (rta.frameCounter >= rta.nFrames))
//     return callbackReturnValue;
//   return 0;
// }


int main( int argc, char *argv[] )
{


    RtAudio dac;
    if ( dac.getDeviceCount() < 1 ) {
      std::cout << "\nNo audio devices found!\n";
      exit( 1 );
    }

     MY_TYPE *data = (MY_TYPE *)calloc(rta.channels, sizeof(MY_TYPE));

    

    // Let RtAudio print messages to stderr.
    dac.showWarnings( true );

 

    if ( rta.device == 0 )
      oParams.deviceId = dac.getDefaultOutputDevice();


    try {
      dac.openStream(&oParams, NULL, FORMAT, rta.fs, &rta.bufferFrames, &sine, (void *)data, &options, &errorCallback);

      //dac.openStream(&oParams, NULL, FORMAT, rta.fs, &(rta.bufferFrames), &sineSweep, (void *)data, &options, &errorCallback);
      dac.startStream();
    }
    catch ( RtAudioError& e ) {
      e.printMessage();
      goto cleanup;
    }

    
    char input;
    //std::cout << "Stream latency = " << dac.getStreamLatency() << "\n" << std::endl;
    std::cout << "\nPlaying ... press <enter> to quit (buffer size = " << rta.bufferFrames << ").\n";
    std::cin.get( input );

    try {
      // Stop the stream
      dac.stopStream();
    }
    catch ( RtAudioError& e ) {
      e.printMessage();
    }


 cleanup:
  if ( dac.isStreamOpen() ) dac.closeStream();
  free( data );

  return 0;
}