// hw422_CAppleMidiSynth.cpp
#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

// #include <AssertMacros.h>

CAppleMidiSynth::CAppleMidiSynth()
{
  // taken from c411_PlaySoftMIDI

  /*=============== From CreateAUGraph() =============== 
  Copy/paste everything from:

  OSStatus result;
  to
  // ok we're good to go - get the Synth Unit...
  __Require_noErr(result = AUGraphNodeInfo(outGraph, synthNode, 0, &outSynth), home);
  ======================================================*/

  /*=============== From main() =============== 
  // ok we're set up to go - initialize and start the outGraph
  __Require_noErr(result = AUGraphInitialize(outGraph), home);

    CAShow(outGraph); // prints out the outGraph so we can see what it looks like...

  __Require_noErr(result = AUGraphStart(outGraph), home);
  ======================================================*/

  /*================= JE modification ===================
home:
  if (result == noErr)
    std::cout << "CAppleMidiSynth() success\n";
  else
    std::cout << "Failed to construct CAppleMidiSynth()\n";
  ======================================================*/
}

CAppleMidiSynth::~CAppleMidiSynth()
{
  if (outGraph)
  {
    // Stop and Dispose AUGraph
  }
}

void CAppleMidiSynth::send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2)
{
  // Called by the next two functions
  // waitTm is calculated by them
  CDelayMs d(waitTm, false);
  MusicDeviceMIDIEvent(outSynth, st, d1, d2, 0);
}

void CAppleMidiSynth::send(const CMidiPacket &mp)
{
  // You know now_time and previous_time
  // Difference is wait time
  // call CAppleMidiSynth::send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2)
  // update previous_time
}

void CAppleMidiSynth::send(const std::vector<CMidiPacket> &vmp)
{
  // figure it out
}