// hw422_CAppleMidiSynth.h
#ifndef HW422_CAPPLE_MIDISYNTH_H_
#define HW422_CAPPLE_MIDISYNTH_H_

#include <CoreServices/CoreServices.h> //for file stuff
#include <AudioUnit/AudioUnit.h>
#include <AudioToolbox/AudioToolbox.h> //for AUGraph

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <vector>

// DO NOT MODIFY

using namespace CMP33;

class CAppleMidiSynth
{
public:
  CAppleMidiSynth();
  virtual ~CAppleMidiSynth();
  CAppleMidiSynth(const CAppleMidiSynth &) = default;
  CAppleMidiSynth(CAppleMidiSynth &&) = default;
  CAppleMidiSynth &operator=(const CAppleMidiSynth &) = default;
  CAppleMidiSynth &operator=(CAppleMidiSynth &&) = default;

  // three overridden send methods
  void send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2);
  void send(const CMidiPacket &mp, uint32_t prev_time);
  void send(const std::vector<CMidiPacket> &vmp);

private:
  AUGraph outGraph;
  AudioUnit outSynth;
};

#endif // HW531_CAPPLEMIDISYNTH_H_