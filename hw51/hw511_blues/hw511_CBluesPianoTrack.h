/***************************************************************
hw511_CBluesPianoTrack.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef HW511_CBLUESPIANOTRACK_H_
#define HW511_CBLUESPIANOTRACK_H_

#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

// DO NOT MODIFY

class CBluesPianoTrack : public CInstrument
{
public:
	// constructor
	CBluesPianoTrack(uint32_t beginTm, uint32_t endTm, int scaleOffset, int chan,
									 int patch, int vol, int pan, int startNote, int meas);

	// This is the only function needed
	void write_one_measure(int meas, int chan) override;
};
#endif // HW511_CBLUESPIANOTRACK_H_