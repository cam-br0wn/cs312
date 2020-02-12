/***************************************************************
hw431_CDrumMachine.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw431
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
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