#ifndef HW423_CALTOTRACK_H_
#include "hw423_CAltoTrack.h"
#endif
#ifndef HW423_CSOPRANOTRACK_H_
#include "hw423_CSopranoTrack.h"
#endif
#ifndef HW423_CBASSTRACK_H_
#include "hw423_CBassTrack.h"
#endif
#include "hw332_CMidiPacket.h"
#include "hw421_CDelayMs.h"
#include "hw422_CAppleMidiSynth.h"

#include <vector>

int main()
{
  // declare soprano track parameters
    uint16_t beginTime = 0;
    uint16_t endTime = 60000;
    uint16_t startNote = 60;
    uint16_t chan = 0;
    uint16_t patch = 15;
    uint16_t vol = 40;
    uint16_t pan = 0; // panned all the way left 
  // Create the soprano track
  CSopranoTrack sop_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // declare alto track parameters that are different from soprano
    beginTime = 8000;
    endTime = 60000;
    startNote = 39;
    chan = 1;
    patch = 17;
    vol = 40;
    pan = 64; // panned to the center
  // Create alto track
  CAltoTrack alto_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // declare bass track parameters that are different from soprano
    beginTime = 16000;
    endTime = 60000;
    startNote = 20;
    chan = 2;
    patch = 16;
    vol = 127;
    pan = 127; // panned all the way to the right
  // Create bass track
  CBassTrack bass_trk(beginTime, endTime, startNote, chan, patch, vol, pan);

  // set the scale and rhythm duration pattern for each track
  // you can choose from the patterns in hw423_CScalesTrack or create your own
    sop_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    sop_trk.vrhythm = {0b1111, 0b1011, 0b1010, 0b1110};
    alto_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    alto_trk.vrhythm = {0b1010, 0b1000, 0b1001, 0b1100};
    bass_trk.vscale = {0, 1, 4, 5, 7, 8, 10, 12};
    bass_trk.vrhythm = {0b1010, 0b1111, 0b1101, 0b1110};

  // Write the three tracks

  // create the playback vector vplay
  // use std::copy for sop_trk, alto_trk, bass_trk with td::back_inserter(vplay)
  std::vector<CMidiPacket> vplay;
  std::back_inserter();

  // vector vplay now holds all elements of sop, alto, bass vectors
  // sort vplay vector
  // it will use your operator< (less) routine

  // Set the playback tempo
  // This is the variable you use
  // The number (120) is passed in from the command line
  CDelayMs::s_tempo = 120;

  // create the CAppleMidiSynth object
  CAppleMidiSynth ams;
  for (auto itr : vplay)
  {
    std::cout << itr;   // send CMidiPackets to cout while playing
    ams.send(itr);      // play the CMidiPacket
  }
}