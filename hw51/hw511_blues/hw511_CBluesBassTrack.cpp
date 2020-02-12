// hw511_CBluesBassTrack.cpp
#ifndef HW511_CBLUESBASSTRACK_H_
#include "hw511_CBluesBassTrack.h"
#endif

// Store note and time together
struct NoteTm
{
  int note;
  int tm;
};

// clang-format off
const std::vector<NoteTm> one_meas_vec = {
                                          {7, 0},
                                          {0, 500},
                                          {9, 1000},
                                          {0, 1500},
                                          {10, 2000},
                                          {0, 2500},
                                          {9, 3000},
                                          {0, 3500}
                                          };
// Alternate choice or write your own
// const std::vector<NoteTm> one_meas_vec = {
//                                           {0, 0},
//                                           {4, 500},
//                                           {7, 1000},
//                                           {9, 1500},
//                                           {10, 2000},
//                                           {9, 2500},
//                                           {7, 3000},
//                                           {4, 3500}
//                                           };
// clang-format on

// additional constructor
CBluesBassTrack::CBluesBassTrack(uint32_t beginTm, uint32_t endTm,
                                 int scaleOffset, int chan, int patch, int vol,
                                 int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesBassTrack::write_one_measure(int meas, int chan)
{
    const int kNOTE_DURATION = 300;
  CMidiPacket mp;

  // use get_note_offset(meas, get_start_note()) to get the pitch offset based on the chord used in meas
  // use get_measure_start_time(meas) to get the starting time for the measure we're writing
    uint32_t meas_tm = get_measure_start_time(meas);
    uint8_t offset = get_note_offset(meas, get_start_note());
  for (auto itr : one_meas_vec)
  {
    // get a random index into vBluesScale
    // set note to vBluesScale.at(index);

    // Use push_non() to write the Note On message
    // Use push_nof() to write the Note Off  message
    push_non(meas_tm + itr.tm, chan, itr.note + offset, 100);
    push_nof(meas_tm + kNOTE_DURATION + itr.tm, chan, itr.note + offset);
  }

  set_meas_num(get_meas_num() + 1);
}