#ifndef HW423_CSOPRANOTRACK_H
#include "hw423_CSopranoTrack.h"
#endif

// The random functions have been moved to a utility unit.
#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

CSopranoTrack::CSopranoTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                             uint8_t patch, uint8_t volume, uint8_t pan)
    : CScalesTrack(beginTime, endTime, noteoffset, channel, patch, volume, pan)
{
}

void CSopranoTrack::write_track()
{
  // set the patch, volume, and pan
  // Note that it's calling the write_track() function in the parent class
  CScalesTrack::write_track();

  // fill the CMidiPacket vector vtrk that was inherited from CMidiTrack class
  // should be similare to what you did for hw413_CScalesTrack
}