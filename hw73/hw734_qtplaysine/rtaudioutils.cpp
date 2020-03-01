#ifndef RTAUDIOUTILS_H_
#include "rtaudioutils.h"
#endif

RtAudio::StreamOptions options;
RtAudio::StreamParameters oParams;
RTA rta;

// constructor
RTA::RTA() : channels{1},
             frameCounter{0},
             checkCount{false},
             nFrames{0},
             bufferFrames{kRTABUFFER_SZ},
             fs{FS},
             device{0},
             offset{0}
{
    oParams.deviceId = device;
    oParams.nChannels = channels;
    oParams.firstChannel = offset;

    options.flags = RTAUDIO_HOG_DEVICE;
    options.flags |= RTAUDIO_SCHEDULE_REALTIME;
    options.flags |= RTAUDIO_NONINTERLEAVED;
}
void errorCallback( RtAudioError::Type type, const std::string& errorText )
{
    // This example error handling function does exactly the same thing
    // as the embedded RtAudio::error() function.
    std::cout << "in errorCallback" << std::endl;
    if ( type == RtAudioError::WARNING )
        std::cerr << '\n'
                  << errorText << "\n\n";
    else if ( type != RtAudioError::WARNING )
        throw( RtAudioError( errorText, type ) );
}