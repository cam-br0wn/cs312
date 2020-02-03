/***************************************************************
 hw413_CMidiTrack.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw413
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#ifndef HW413_CMIDITRACK_H_
#include "hw413_CMidiTrack.h"
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
void CMidiTrack::send_non(uint32_t tm, uint8_t chan, uint8_t note, uint8_t vel)
{
  // I did the first one
  CMidiPacket mp(tm, 0x90 + chan, note, vel);
  mp.print();
}

void CMidiTrack::send_nof(uint32_t tm, uint8_t chan, uint8_t note)
{
  CMidiPacket mp(tm, 0x80 + chan, note, 0);
  mp.print();
}

void CMidiTrack::send_patch(uint32_t tm, uint8_t chan, uint8_t patch)
{
  CMidiPacket mp(tm, 0xC0 + chan, patch);
  mp.print();
}

void CMidiTrack::send_volume(uint32_t tm, uint8_t chan, uint8_t vol)
{
  CMidiPacket mp(tm, 0xB0 + chan, 7, vol);
  mp.print();
}

void CMidiTrack::send_pan(uint32_t tm, uint8_t chan, uint8_t pan)
{
  CMidiPacket mp(tm, 0xB0 + chan, 10, pan);
  mp.print();
}

void CMidiTrack::send_expression(uint32_t tm, uint8_t chan, uint8_t expr)
{
  CMidiPacket mp(tm, 0xB0 + chan, 11, expr);
  mp.print();
}