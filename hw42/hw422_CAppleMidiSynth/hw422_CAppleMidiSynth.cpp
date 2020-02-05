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

  OSStatus result;
	//create the nodes of the graph
	AUNode synthNode, limiterNode, outNode;

	AudioComponentDescription cd;
	cd.componentManufacturer = kAudioUnitManufacturer_Apple;
	cd.componentFlags = 0;
	cd.componentFlagsMask = 0;

	__Require_noErr(result = NewAUGraph(&outGraph), home);

	cd.componentType = kAudioUnitType_MusicDevice;
	cd.componentSubType = kAudioUnitSubType_DLSSynth;

	__Require_noErr(result = AUGraphAddNode(outGraph, &cd, &synthNode), home);

	cd.componentType = kAudioUnitType_Effect;
	cd.componentSubType = kAudioUnitSubType_PeakLimiter;

	__Require_noErr(result = AUGraphAddNode(outGraph, &cd, &limiterNode), home);

	cd.componentType = kAudioUnitType_Output;
	cd.componentSubType = kAudioUnitSubType_DefaultOutput;
	__Require_noErr(result = AUGraphAddNode(outGraph, &cd, &outNode), home);

	__Require_noErr(result = AUGraphOpen(outGraph), home);

	__Require_noErr(result = AUGraphConnectNodeInput(outGraph, synthNode, 0, limiterNode, 0), home);
	__Require_noErr(result = AUGraphConnectNodeInput(outGraph, limiterNode, 0, outNode, 0), home);
  	
    // ok we're good to go - get the Synth Unit...
	__Require_noErr(result = AUGraphNodeInfo(outGraph, synthNode, 0, &outSynth), home);

  // ok we're set up to go - initialize and start the outGraph
  __Require_noErr(result = AUGraphInitialize(outGraph), home);

    CAShow(outGraph); // prints out the outGraph so we can see what it looks like...

  __Require_noErr(result = AUGraphStart(outGraph), home);


home:
  if (result == noErr)
    std::cout << "CAppleMidiSynth() success\n";
  else
    std::cout << "Failed to construct CAppleMidiSynth()\n";
}

CAppleMidiSynth::~CAppleMidiSynth()
{
  if (outGraph)
  {
    AUGraphStop(outGraph); 
		DisposeAUGraph(outGraph);
  }
}

void CAppleMidiSynth::send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2)
{
  // Called by the next two functions
  // waitTm is calculated by them
  CDelayMs d(waitTm, false);
  MusicDeviceMIDIEvent(outSynth, st, d1, d2, 0);
}

void CAppleMidiSynth::send(const CMidiPacket &mp, uint32_t prev_time)
{
  u_int32_t prev = prev_time;
  u_int32_t now_time = mp.get_timestamp(); 

  // You know now_time and previous_time
  // Difference is wait time
  u_int32_t wait_time = (now_time - prev);

  // call CAppleMidiSynth::send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2)
  // update previous_time
  send(wait_time, mp.get_status(), mp.get_data1(), mp.get_data2());
}

void CAppleMidiSynth::send(const std::vector<CMidiPacket> &vmp)
{
  for (int i = 0; i < vmp.size(); i++) {
    u_int32_t prev_time;
    if (i == 0) {
      prev_time = 0;
    } else {
      prev_time = vmp.at(i-1).get_timestamp();
    }
    
    send(vmp.at(i), prev_time);
  }
}