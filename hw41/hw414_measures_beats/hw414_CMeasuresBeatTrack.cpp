/***************************************************************
 hw414_CMeasuresBeatTrack.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw414
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW414_CMEASURESBEATTRACK_H_
#include "hw414_CMeasuresBeatTrack.h"
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif
// FOR REFERENCE
// assign scale - choose 1
// vmajor_pentatonic{0, 2, 4, 7, 9, 12};        // Major pentatonic
// vminor_pentatonic{0, 3, 5, 7, 10, 12};       // Minor pentatonic
// vragtime{0, 2, 3, 4, 7, 9, 12};              // Ragtime scalef
// vrock_blues{0, 3, 4, 7, 9, 10, 12};          // Rock blues Scales
// vminor_blues{0, 3, 5, 6, 7, 10, 12};         // Minor blues Scales
// vheptatonic_blues{0, 2, 3, 5, 6, 9, 10, 12}; // Heptatonic blues Scales
// vmideast{0, 1, 4, 5, 7, 8, 10, 12};          // Middle Eastern scale
// vjapanese{0, 1, 5, 7, 8, 12};                // Japanese scale
// voctotonic{0, 1, 3, 4, 6, 7, 9, 10, 12};     // Octotonic jazz scale half step, whole step
// vwholetone{0, 2, 4, 6, 8, 10, 12};           // Sc-fi
// vflamenco{0, 1, 4, 5, 7, 8, 11, 12};         // Flamenco
// vphrygian_dominant{0, 1, 4, 5, 7, 8, 10, 12};// Phrygian_dominant

int CMeasuresBeatTrack::numMeas = 12;

// Examples of using beat patterns
// Uncomment 1 from this list
// Make up your own.
// std::vector<std::string> vbeats = {
//     b0000, b0001, b0010, b0011,
//     b0100, b0101, b0110, b0111, 
//     b1000, b1001, b1010, b1011,
//     b1100, b1101, b1110, b1111};
// std::vector<std::string> vbeats = {b1000, b1010, b1011};
// std::vector<std::string> vbeats = {b1000, b0100, b0001};
// std::vector<std::string> vbeats = {b1000, b0001};
// std::vector<std::string> vbeats = {b1000, b1010};
// std::vector<std::string> vbeats = {b1000, b0110};
// std::vector<std::string> vbeats = {b0000, b1000, b0110};
//  std::vector<std::string> vbeats = {b1000};
// std::vector<std::string> vbeats = {b0000, b0000, b0001, b0110};
std::vector<std::string> vbeats = {b0011, b0110, b0001, b0010, b1111};
// only constructor.
CMeasuresBeatTrack::CMeasuresBeatTrack(uint32_t beginTime,
                                       uint32_t endTime,
                                       uint8_t noteoffset,
                                       uint8_t channel,
                                       uint8_t patch,
                                       uint8_t volume,
                                       uint8_t pan)
    : CMidiTrack(beginTime, endTime, noteoffset, channel, patch, volume, pan), tm{beginTime}
{ // choose one scale above
  vscale = vmajor_pentatonic;
  // choose an example beat pattern from examples above
  // or make up your own
}

void CMeasuresBeatTrack::write_one_beat()
{
    std::string beat_pattern = vbeats[get_rand_int(1, vbeats.size()) - 1];
    for(int i = 0; i < 4; i++){
        int scale_note_offset_index = get_rand_int(0, vscale.size()-1);
        uint8_t scale_note_offset = vscale[scale_note_offset_index] + get_noteOffset();
        if(beat_pattern.at(i) == '1'){
            send_non(tm, get_channel(), scale_note_offset, 127);
            tm += 250;
            send_nof(tm - 1, get_channel(), scale_note_offset);
        }
        else{
            tm += 250;
        }
    }
  /* pseudo code
    create a string from a random index into vbeats
    for loop 0 to string length
      get a random scale noteoffset
      cycle through the binary digits of the vbeat string
      if it's one
        send NON
        increment tm by 250
        send NOF at tm - 1
      else if it's zero
        increment tm by 250
    end for loop
*/ 
}

void CMeasuresBeatTrack::write_one_measure()
{
  // we're using 4 beats in a measure 
  // write the measure
  for(int b = 0; b < 4; b++){
      write_one_beat();
  }

}


void CMeasuresBeatTrack::write_track()
{
  vtrk.clear(); // from CMidiTrack
  // these messages should come at timestamp 0 before any NON
  send_patch(0, get_channel(), get_patch());
  send_volume(0, get_channel(), get_volume());
  send_pan(0, get_channel(), get_pan());
  for(int m = 0; m < numMeas; m++){
      write_one_measure();
  }
   /*
      the static variable CMeasuresBeatTrack::numMeas
      indicates how many measures long the song is

      for the number of measures in the song
      write_one_measure();
    */
}