/***************************************************************
hw511_CBluesMelodyTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef HW511_CBLUESMELODYTRACK_H_
#include "hw511_CBluesMelodyTrack.h"
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

#include <cstdint>
#include <vector>

const std::vector<int> vBluesScale = {0, 3, 4, 7, 9, 10, 12}; // rock blues scale
const std::vector<uint32_t> vTime = {500, 1000, 1500, 2000, 2500};

// set to 1 to use markov
// wet to 0 to use random
#define USE_MARKOV 1
#if USE_MARKOV
#ifndef C513_CMARKOVBLUES_H_
#include "c513_CMarkovBlues.h"
#endif
#endif

// additional constructor
CBluesMelodyTrack::CBluesMelodyTrack(uint32_t beginTm, uint32_t endTm,
                                     int scaleOffset, int chan, int patch, int vol,
                                     int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesMelodyTrack::write_one_measure(int meas, int chan)
{
  // kNOTE_DURATION has to be smaller than smallest delta time difference in vTime
  const int kNOTE_DURATION = 300;
  CMidiPacket mp;

#if USE_MARKOV
    CMarkovBlues mb;
    // choose starting notes only on 0,4,7 of the scale
    int n = get_rand_int(0, 2);
    int note{0};
    if (meas % 12 == 0)
        note = vBluesScale.at(0);
    else if (n == 1)
        note = vBluesScale.at(4);
    else if (n == 3)
        note = vBluesScale.at(7);
    else
        note = vBluesScale.at(0);
#endif

  // use get_note_offset(meas, get_start_note()) to get the pitch offset based on the chord used in meas
  // use get_measure_start_time(meas) to get the starting time for the measure we're writing
  uint32_t meas_tm = get_measure_start_time(meas);
  uint8_t offset = get_note_offset(meas, get_start_note());

  for (auto itr : vTime)
  {
    // get a random index into vBluesScale
    // set note to vBluesScale.at(index);

    // Use push_non() to write the Note On message
    // Use push_nof() to write the Note Off  message
    #if USE_MARKOV
        note = mb.chooseMarkovNote(note);
    #else
        int ni = get_rand_int(0, vBluesScale.size() - 1);
        int note = vBluesScale.at(ni);
    #endif

    push_non(meas_tm + itr, chan, note + offset, 100);
    push_nof(meas_tm + kNOTE_DURATION + itr, chan, note + offset);
  }

  set_meas_num(get_meas_num() + 1);
  std::cout << "Write: CBluesMelodyTrack::write_one_measure(int meas, int chan)\n";
}