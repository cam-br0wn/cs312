#ifndef HW423_CALTOTRACK_H_
#include "hw423_CAltoTrack.h"
#endif

#ifndef HW423_CSOPRANOTRACK_H_
#include "hw423_CSopranoTrack.h"
#endif

#ifndef HW423_CBASSTRACK_H_
#include "hw423_CBassTrack.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW421_CDELAY_MS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
  // declare soprano track parameters
    uint16_t beginTime = 0;
    uint16_t endTime = 60000;
    uint16_t startNote = 72;
    uint16_t chan = 0;
    uint16_t patch = 15;
    uint16_t vol = 90;
    uint16_t pan = 0; // panned all the way left 
  // Create the soprano track
  CSopranoTrack sop_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // declare alto track parameters that are different from soprano
    beginTime = 8000;
    endTime = 60000;
    startNote = 60;
    chan = 1;
    patch = 17;
    vol = 100;
    pan = 64; // panned to the center
  // Create alto track
  CAltoTrack alto_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // declare bass track parameters that are different from soprano
    beginTime = 16000;
    endTime = 60000;
    startNote = 48;
    chan = 2;
    patch = 16;
    vol = 120;
    pan = 127; // panned all the way to the right
  // Create bass track
  CBassTrack bass_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // set the scale and rhythm duration pattern for each track
  // you can choose from the patterns in hw423_CScalesTrack or create your own
    sop_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    // sop_trk.vrhythm = {0b1111, 0b1011, 0b1010, 0b1110};
    sop_trk.vrhythm = vrhythm3;
    alto_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    // alto_trk.vrhythm = {0b1010, 0b1000, 0b1001, 0b1100};
    alto_trk.vrhythm = vrhythm3;
    bass_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    // bass_trk.vrhythm = {0b1010, 0b1111, 0b1101, 0b1110};
    bass_trk.vrhythm = vrhythm3;

  // Write the three tracks
  sop_trk.write_track();
  alto_trk.write_track();
  bass_trk.write_track();
  // create the playback vector vplay
  // use std::copy for sop_trk, alto_trk, bass_trk with std::back_inserter(vplay)
  std::vector<CMP33::CMidiPacket> vplay;
  std::copy(sop_trk.vtrk.begin(), sop_trk.vtrk.end(), std::back_inserter(vplay));
  std::copy(alto_trk.vtrk.begin(), alto_trk.vtrk.end(), std::back_inserter(vplay));
  std::copy(bass_trk.vtrk.begin(), bass_trk.vtrk.end(), std::back_inserter(vplay));

  // vector vplay now holds all elements of sop, alto, bass vectors
  // sort vplay vector
  // it will use your operator< (less) routine
  std::sort(vplay.begin(), vplay.end());

  // Set the playback tempo
  // This is the variable you use
  // The number (120) is passed in from the command line
//  CDelayMs::s_tempo = std::atoi(argv[1]);
CDelayMs::s_tempo = 120;
  // create the CAppleMidiSynth object
  CAppleMidiSynth ams;
    for (auto itr:vplay)
        ams.send(itr);
//  ams.send(vplay);
}
