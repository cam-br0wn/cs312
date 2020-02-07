#ifndef HW423_CBASSTRACK_H_
#include "hw423_CBassTrack.h"
#endif

// The random functions have been moved to a utility unit.
#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

CBassTrack::CBassTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                             uint8_t patch, uint8_t volume, uint8_t pan)
    : CScalesTrack(beginTime, endTime, noteoffset, channel, patch, volume, pan)
{
}

void CBassTrack::write_bass_track()
{
  int rhythm_index = 0;
  int tm = get_beginTimestamp();
  uint8_t channel = get_channel();
  do {
      int note = get_note();
      uint8_t vel = 100;
      if(!(rhythm_index % (vrhythm.size() - 1))) vel = 127; // makes velocity 127 if it's the first note in the rhythm
      push_non(tm, channel, note, vel);
      push_nof(tm + vrhythm[rhythm_index % vrhythm.size()] - 1, channel, note);
      tm += vrhythm[rhythm_index];
      rhythm_index++;
  }
  while(tm < get_endTimestamp());
  /*
  CScalesTrack declares a private variable tm for keeping track
  I used a do..while loop because we set the endTime in the constructor
  do {
    get a random note from vscale
    vrhythm has 4 elements
    every time you get a new NON you'll have cycle through vrhythm 
        indices using the pattern 0 1 2 3 0 1 2 3 etc.
    every time it's vrhythm[0] the NON velocity is 127
    otherwise the NON velocity is 80.
    this will accent the first note of rhythm pattern every time it repeats.
    keep a running sum of the timestamps using the tm variable
    if the NON timestamp is tm, the NOF timestamp is tm - 1
  } while (tm < get_endTimestamp());
  */
}

void CBassTrack::write_track()
{
  // uint8_t patch = get_patch();
  // uint8_t volume = get_volume();
  // uint8_t pan = get_pan();

  // set the patch, volume, and pan
  // Note that it's calling the write_track() function in the parent class
  CScalesTrack::write_track();
  write_bass_track();

  // fill the CMidiPacket vector vtrk that was inherited from CMidiTrack class
  // should be similare to what you did for hw413_CScalesTrack
}