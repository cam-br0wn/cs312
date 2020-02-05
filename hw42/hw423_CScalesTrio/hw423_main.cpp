#ifndef XXX_H_
#include "necessary.h"
#endif
etc.

int main()
{
  // declare soprano track parameters
  //   uint16_t beginTime = ;
  //   uint16_t startNote = ;
  //   uint16_t chan = ;
  //   uint16_t patch = ;
  //   uint16_t vol = ;
  //   uint16_t pan = ;
  // Create the soprano track
  CSopranoTrack sop_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  // declare alto track parameters that are different from soprano
  //   beginTime = ;
  //   startNote = ;
  //   chan = ;
  //   patch = ;
  //   vol = ;
  //   pan = ;
  // Create alto track
  CAltoTrack alto_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  // declare bass track parameters that are different from soprano
  //   beginTime = ;
  //   startNote = ;
  //   chan = ;
  //   patch = ;
  //   vol = ;
  //   pan = ;
  // Create bass track
  CBassTrack bass_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  // set the scale and rhythm duration pattern for each track
  // you can choose from the patterns in hw423_CScalesTrack or create your own
  //   sop_trk.vscale = ;
  //   sop_trk.vrhythm = ;
  //   alto_trk.vscale = ;
  //   alto_trk.vrhythm = ;
  //   bass_trk.vscale = ;
  //   bass_trk.vrhythm = };

  // Write the three tracks

  // create the playback vector vplay
  // use std::copy for sop_trk, alto_trk, bass_trk with td::back_inserter(vplay)

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
    std::cout << itr; // send CMidiPackets to cout while playing
    ams.send(itr);    // play the CMidiPacket
  }
}