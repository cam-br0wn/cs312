/***************************************************************
 hw414_main.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw414
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW414_CMeasuresBeatTrack_H_
#include "hw414_CMeasuresBeatTrack.h"
#endif

#include <iostream>

// DO NOT MODIFY

int main()
{
  // calc end time based on number measures
  uint32_t nm = CMeasuresBeatTrack::numMeas * 4000;

  // beginTS, endTS, noteOffset, channel, patch, volume, pan
  CMeasuresBeatTrack mtrk{0, nm, 60, 0, 11, 100, 64};

  mtrk.write_track();
  for (auto itr : mtrk.vtrk)
    std::cout << itr;

  std::cout << "# Play in MIDIDisplay\n";
}