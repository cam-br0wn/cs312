/***************************************************************
hw431_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw431
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef hw431_CDRUMACHINE_H_
#include "hw431_CDrumMachine.h"
#endif

#ifndef hw423_CMIDITRACK_H
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <iostream>

using namespace CMP33;

int main()
{
  // declare the playback vector
  std::vector<CMidiPacket> vplay;

  // create the drum machine
  CDrumMachine dm;

  // stuff each row into the dm.tracks vector
  dm.make_track(kBASS_DRUM, {"1000", "1000", "1000", "1000"});
  dm.make_track(kSNARE_DRUM, {"0001", "0010", "0001", "0010"});
  dm.make_track(kCLAP, {"0000", "0000", "0000", "0010"});
  dm.make_track(kCLOSED_HIHAT, {"1000", "1000", "1000", "1000"});
  dm.make_track(kOPEN_HIHAT, {"0010", "0010", "0010", "0011"});
  dm.make_track(kLOW_TOM, {"0010", "0000", "0000", "0000"});
  dm.make_track(kHIGH_TOM, {"0001", "0001", "0010", "0010"});
  dm.make_track(kSIDE_STICK, {"0010", "0100", "0100", "0101"});


  std::cout << "main(): you need to implement the for loop\n";
  for (auto n = 0; n < dm.vDrumTracks.size(); ++n)
  {
    dm.vDrumTracks[n].write_track(4); // repeat each row 4x
    //   use std::copy(...) to stuff each of the eight vDrumTracks[n] into vplay
    std::copy(dm.vDrumTracks[n].vtrk.begin(), dm.vDrumTracks[n].vtrk.end(), std::back_inserter(vplay));
//    std::cout << "main(): use std::copy(...) to stuff every vDrumTracks[n] into vplay\n";
  }
  sort(vplay.begin(), vplay.end());

  // use std::sort(...) to sort vplay
  std::cout << "main(): use std::sort(...) to sort vplay\n";

  // write vplay to std::cout
  std::cout << "main(): write vplay to std::cout\n";

  // set the CDelayMs::s_tempo, try 75
  std::cout << "main(): set the CDelayMs::s_tempo to 75\n";

  CDelayMs::s_tempo = 75;
  CAppleMidiSynth ams;
    ams.send(vplay);
};
