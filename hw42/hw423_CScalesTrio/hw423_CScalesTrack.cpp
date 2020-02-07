/***************************************************************
 hw413_CScalesTrack.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw413
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

// in common folder
#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

// FOR REFERENCE
// assign scale - choose 1
// vmajor_pentatonic{0, 2, 4, 7, 9, 12};        // Major pentatonic
// vminor_pentatonic{0, 3, 5, 7, 10, 12};       // Minor pentatonic
// vragtime{0, 2, 3, 4, 7, 9, 12};              // Ragtime scale
// vrock_blues{0, 3, 4, 7, 9, 10, 12};          // Rock blues Scales
// vminor_blues{0, 3, 5, 6, 7, 10, 12};         // Minor blues Scales
// vheptatonic_blues{0, 2, 3, 5, 6, 9, 10, 12}; // Heptatonic blues Scales
// vmideast{0, 1, 4, 5, 7, 8, 10, 12};          // Middle Eastern scale
// vjapanese{0, 1, 5, 7, 8, 12};                // Japanese scale
// voctotonic{0, 1, 3, 4, 6, 7, 9, 10, 12};     // Octotonic jazz scale half step, whole step
// vwholetone{0, 2, 4, 6, 8, 10, 12};           // Sc-fi
// vflamenco{0, 1, 4, 5, 7, 8, 11, 12};         // Flamenco
// vphrygian_dominant{0, 1, 4, 5, 7, 8, 10, 12};// Phrygian_dominant

// additional constructor.
CScalesTrack::CScalesTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                           uint8_t patch, uint8_t volume, uint8_t pan)
    : CMidiTrack(beginTime, endTime, noteoffset, channel,
                 patch, volume, pan)
{
  std::vector<int> vscale;
  std::vector<int> vrhythm;
}

int CScalesTrack::get_note()
{
  // get a random note from the vscale
  // add the get_noteOffset
  // return the result
  int index = get_rand_int(0, vscale.size()-1);
  return get_noteOffset() + vscale.at(index);
}
/*
0 500 750 1000 1500
*/
void CScalesTrack::write_scales_track()
{
  int rhythm_index = 0;
  uint32_t time_stamp = get_beginTimestamp();
  uint8_t channel = get_channel();
  do {
      int note = get_note();
      uint8_t vel;
      if(time_stamp % 1500 == 0){
        vel = 127;
      }
      else{
          vel = 80;
      }
      push_non(time_stamp, channel, note, vel);
      push_nof(time_stamp + vrhythm[rhythm_index] - 1, channel, note);

      time_stamp += vrhythm[rhythm_index];

      if(rhythm_index == vrhythm.size()-1){
          rhythm_index = 0;
      }
      else{
          rhythm_index++;
      }
  }
  while(time_stamp < get_endTimestamp());
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

void CScalesTrack::write_track()
{
  vtrk.clear();
  // these items should be set at the beginning of the track
  push_patch(0, get_channel(), get_patch());
  push_volume(0, get_channel(), get_volume());
  push_pan(0, get_channel(), get_pan());
}
