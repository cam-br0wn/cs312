// hw511_CBluesPianoTrack.h
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