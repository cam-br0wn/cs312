// hw431_CDrumMachine.h
#ifndef hw431_CDRUMMACHINE_H_
#define hw431_CDRUMMACHINE_H_

#ifndef hw431_CDRUMTRACK_H_
#include "hw431_CDrumTrack.h"
#endif

#include <cstdint>
#include <vector>

// DO NOT MODIFY

// You can add others
// Look up drum note numbers using the CS312 tool gmdrums
// Note: zero is not the correct number
const uint8_t kBASS_DRUM = 36;
const uint8_t kSNARE_DRUM = 38;
const uint8_t kCLAP = 39;
const uint8_t kCLOSED_HIHAT = 42;
const uint8_t kOPEN_HIHAT = 46;
const uint8_t kLOW_TOM = 41;
const uint8_t kHIGH_TOM = 48;
const uint8_t kSIDE_STICK = 37;
const uint8_t kWOOD_BLOCK = 76;

// DO NOT MODIFY class CDrumMachine
class CDrumMachine
{
public:
  // This vector holds all eight drum tracks (rows)
  std::vector<CDrumTrack> vDrumTracks;

  // the big 6 are all default constructed
  void make_track(const uint8_t note, const std::vector<std::string> &pats);
};

#endif // hw431_CDRUMMACHINE_H_