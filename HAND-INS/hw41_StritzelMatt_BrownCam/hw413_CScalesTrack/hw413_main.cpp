/***************************************************************
 hw413_main.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw413
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW413_CSCALESTRACK_H_
#include "hw413_CScalesTrack.h"
#endif

#include <iostream>

// DO NOT MODIFY

int main()
{
  // beginTS, endTS, noteOffset, channel, patch, volume, pan
  CScalesTrack mtrk{0, 50000, 60, 0, 11, 100, 64};
  mtrk.write_track();
  for (auto itr : mtrk.vtrk)
    std::cout << itr;

  std::cout << "# Play in MIDIDisplay\n";
}