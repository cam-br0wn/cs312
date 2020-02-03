/***************************************************************
 hw414_CMeasuresBeatTrack.h
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw414
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW414_CMEASURESBEATTRACK_H_
#define HW414_CMEASURESBEATTRACK_H_

// now in common folder
#ifndef HW413_CMIDITRACK_H_
#include "hw413_CMidiTrack.h"
#endif

// DO NOT MODIFY THIS CODE

/*
 One beat is one quarter note is 1000 ms
 We'll divide a beat into 4 subdivisions
 In music that means allowed note values are quarter, eighth, sixteenth
 We won't deal with dotted notes.
 Each subdivision will be 250 ms.
 There will be 16 subdivisions based on 4 bit binary strings
*/
// binary counting 0-15
const std::string b0000 = "0000";
const std::string b0001 = "0001";
const std::string b0010 = "0010";
const std::string b0011 = "0011";
const std::string b0100 = "0100";
const std::string b0101 = "0101";
const std::string b0110 = "0110";
const std::string b0111 = "0111";
const std::string b1000 = "1000";
const std::string b1001 = "1001";
const std::string b1010 = "1010";
const std::string b1011 = "1011";
const std::string b1100 = "1100";
const std::string b1101 = "1101";
const std::string b1110 = "1110";
const std::string b1111 = "1111";

class CMeasuresBeatTrack : public CMidiTrack
{
private:
  uint32_t tm;

public:
  static int numMeas;
  std::vector<int> vscale;

  CMeasuresBeatTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                     uint8_t patch, uint8_t volume, uint8_t pan);

  void write_one_beat();
  void write_one_measure();
  virtual void write_track(); // must define it was declared pure virtual in CMidiTrack
};

/*
 There are eleven notes in the chromatic scale numbered 0,1,2,3..11.
 Note 12 is one octave higher than note 0 and is also included.
 The sequence can repeat an octave higher by adding 12 to every note
 The sequence can repeat an octave lower by subracting 12 from every note
 The usable range of MIDI starting note offset is roughly 24-96
 */

// SCALE NOTES
// You can add your own to the list.
// clang-format off
// a much larger list can be found start with
// https://en.wikipedia.org/wiki/Scale_(music)
const std::vector<int> vmajor_pentatonic{0, 2, 4, 7, 9, 12};        // Major pentatonic
const std::vector<int> vminor_pentatonic{0, 3, 5, 7, 10, 12};       // Minor pentatonic
const std::vector<int> vragtime{0, 2, 3, 4, 7, 9, 12};              // Ragtime scale
const std::vector<int> vrock_blues{0, 3, 4, 7, 9, 10, 12};          // Rock blues Scales
const std::vector<int> vminor_blues{0, 3, 5, 6, 7, 10, 12};         // Minor blues Scales
const std::vector<int> v6note_blues{0, 3, 5, 6, 7, 10, 12};         // 6 note blues Scales
const std::vector<int> v7note_blues{0, 2, 3, 5, 6, 9, 10, 12};      // 7 note blues Scales
const std::vector<int> vmideast{0, 1, 4, 5, 6, 8, 11, 12};          // Middle Eastern scale
const std::vector<int> vjapanese{0, 1, 5, 7, 8, 12};                // Japanese scale
const std::vector<int> voctotonic{0, 1, 3, 4, 6, 7, 9, 10, 12};     // Octotonic jazz scale half step, whole step
const std::vector<int> vwholetone{0, 2, 4, 6, 8, 10, 12};           // Whole tone, whole step, whole step
const std::vector<int> vflamenco{0, 1, 4, 5, 7, 8, 11, 12};          // Flamenco
const std::vector<int> vphrygian_dominant{0, 1, 4, 5, 7, 8, 10, 12}; // Phrygian dominant
// clang-format ON

extern std::vector<std::string> vbeats;

#endif // HW414_CMEASURESBEATTRACK_H_