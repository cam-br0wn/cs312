/***************************************************************
hw511_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

#ifndef HW511_CBLUEMELODYTRACk_H
#include "hw511_CBluesMelodyTrack.h"
#endif

#ifndef HW511_CBLUESPIANOTRACK_H
#include "hw511_CBluesPianoTrack.h"
#endif

#ifndef HW511_CBLUESBASSTRACK_H
#include "hw511_CBluesBassTrack.h"
#endif

#ifndef hw431_CDRUMMACHINE_H_
#include "hw431_CDrumMachine.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <vector>

using namespace CMP33;

std::vector<CMidiPacket> vplay;

void write_melody()
{
  // S A X
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 0;
  int patch = 12; // marimba
  // Other atches I tried
  // Tenor Sax
  // Electric Guitar (jazz)
  // Drawbar organ
  // Lead 2 (sawtooth)
  // Clarinet

  int vol = 127;
  int pan = 32; // pan left -32 from center 64
  int startNote = 60;
  int meas = 0;

  // create the saxophone track
  CBluesMelodyTrack sax_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch, vol,
                         pan, startNote, meas);
  sax_trk.write_track();
  // append to vplay
  std::copy(sax_trk.vtrk.begin(), sax_trk.vtrk.end(),
            std::back_inserter(vplay));
}

void write_piano()
{
  // P I A N O
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 1;
  int patch = 22; // harmonica
  int vol = 127;
  int pan = 64; // pan center
  int startNote = 48;
  int meas = 0;

  CBluesPianoTrack pno_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch,
                           vol, pan, startNote, meas);
  pno_trk.write_track();
  // append to vplay
  std::copy(pno_trk.vtrk.begin(), pno_trk.vtrk.end(),
            std::back_inserter(vplay));
}

void write_bass()
{
  // B A S S
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 2;
  int patch = 38; // acoustic bass
  int vol = 127;
  int pan = 92; // pan right +32 from center 64
  int startNote = 36;
  int meas = 0;

  CBluesBassTrack bass_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch,
                           vol, pan, startNote, meas);
  bass_trk.write_track();
  // append to vplay
  std::copy(bass_trk.vtrk.begin(), bass_trk.vtrk.end(),
            std::back_inserter(vplay));
}

void write_drums()
{
  const uint8_t kRIDE_CYMBAL = 51;

  // create the drum machine
  // You do not have to use every row
  // This is the pattern I made up
  // You can make up your own.
  CDrumMachine dm;
  dm.make_track(kBASS_DRUM, {"1000", "1000", "1000", "1000"});
  dm.make_track(kSNARE_DRUM, {"0001", "0010", "0001", "0010"});
  dm.make_track(kCLAP, {"0000", "0000", "0000", "0010"});
  dm.make_track(kRIDE_CYMBAL, {"1000", "1000", "1000", "1000"});
  dm.make_track(kCLOSED_HIHAT, {"0010", "0010", "0010", "0011"});
  dm.make_track(kLOW_TOM, {"0010", "0000", "0000", "0000"});
  dm.make_track(kHIGH_TOM, {"0001", "0001", "0010", "0010"});
  dm.make_track(kWOOD_BLOCK, {"0010", "0100", "0100", "0101"});

  int loops = kSONG_END_TIME / 4000;
  for (auto n = 0; n < dm.vDrumTracks.size(); ++n)
  {
    dm.vDrumTracks[n].write_track(loops);
    // append each drum track to vplay
    std::copy(dm.vDrumTracks[n].vtrk.begin(),
              dm.vDrumTracks[n].vtrk.end(), std::back_inserter(vplay));
  }
}

int main()
{
  // write tracks
  write_melody();
  write_piano();
  write_bass();
  write_drums();

  // sort the playback vector using CMidiPacket43::operator<
  std::sort(vplay.begin(), vplay.end());

  // output for MIDIDisplay
  for (auto itr : vplay)
    std::cout << itr;

  CDelayMs::s_tempo = 125;
  CAppleMidiSynth ams;
  ams.send(vplay);
}