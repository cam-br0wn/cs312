// hw431_CDrumMachine.cpp
#ifndef hw431_CDRUMMACHINE_H_
#include "hw431_CDrumMachine.h"
#endif

// DO NOT MODIFY

void CDrumMachine::make_track(const uint8_t note, const std::vector<std::string> &pats)
{
  CDrumTrack dt;
  dt.init_note_pats(note, pats);
  vDrumTracks.push_back(dt);
}