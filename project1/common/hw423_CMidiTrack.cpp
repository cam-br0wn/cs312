// hw423_CMidiTrack.cpp
#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#include <iostream>

using namespace CMP33;

// This constructor initializes the class variables
// Subclasses can add additional parameters or class variables as needed
CMidiTrack::CMidiTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                       uint8_t patch, uint8_t volume, uint8_t pan, uint8_t expr)
    : beginTimestamp_{beginTime}, endTimestamp_{endTime}, noteOffset_{noteoffset}, channel_{channel},
      patch_{patch}, volume_{volume}, pan_{pan}
{
} // expr not set because it defaults to 100.

// Functions to send MIDI messages
// for now send means write to std::cout
void CMidiTrack::push_non(uint32_t tm, uint8_t chan, uint8_t note, uint8_t vel)
{
  // I did the first one
  CMidiPacket mp(tm, 0x90 + chan, note, vel);
  vtrk.push_back(mp);
}

void CMidiTrack::push_nof(uint32_t tm, uint8_t chan, uint8_t note)
{
  CMidiPacket mp(tm, 0x80 + chan, note, 0);
  vtrk.push_back(mp);
}

void CMidiTrack::push_patch(uint32_t tm, uint8_t chan, uint8_t patch)
{
  CMidiPacket mp(tm, 0xC0 + chan, patch);
  vtrk.push_back(mp);
}

void CMidiTrack::push_volume(uint32_t tm, uint8_t chan, uint8_t vol)
{
  CMidiPacket mp(tm, 0xB0 + chan, 7, vol);
  vtrk.push_back(mp);
}

void CMidiTrack::push_pan(uint32_t tm, uint8_t chan, uint8_t pan)
{
  CMidiPacket mp(tm, 0xB0 + chan, 10, pan);
  vtrk.push_back(mp);
}

void CMidiTrack::push_expression(uint32_t tm, uint8_t chan, uint8_t expr)
{
  CMidiPacket mp(tm, 0xB0 + chan, 11, expr);
  vtrk.push_back(mp);
}
