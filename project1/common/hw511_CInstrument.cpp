// hw511_CInstrument.cpp
#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

// additional constructor
CInstrument::CInstrument(uint32_t beginTm, uint32_t endTm, int noteOffset,
												 int chan, int patch, int vol, int pan, int startNote,
												 int measNum)
		: CMidiTrack(beginTm, endTm, noteOffset, chan, patch, vol, pan),
			start_note{startNote},
			meas_num{measNum}
{
}

// This is a pure virtual function in CInstrument and we need to implement it
// here. This CInstrument function does not implement write_one_measure() and
// instead calls the functions implemented in sax, piano, and bass CInstrument
// subclasses.
void CInstrument::write_track()
{
	vtrk.clear();
	push_patch(0, get_channel(), get_patch());
	push_volume(0, get_channel(), get_volume());
	push_pan(0, get_channel(), get_pan());

	// Calls write_one_measure(), however because it is a pure virtual function
	// it will be implemented in each of the Sax, Piano, and Bass subclasses
	// according to the needs of that subclass
	for (int ix = 0; ix < kTOTAL_MEASURES; ++ix)
		write_one_measure(ix, get_channel());
}

// changes the note offset based on which measure
// of the blues form is being written
// measure numbers are zero based; measure 1 == 0, measure 12 == 11
// Return the scale note offset for meas_num
// A 12 bar blues with 4 repeats means you have to account for measures 13-48
int CInstrument::get_note_offset(int meas, int note_offset)
{
	uint16_t offset;
	switch (meas % 12)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 6:
	case 7:
	case 10:
		offset = note_offset;
		break;
	case 4:
	case 5:
	case 9:
		offset = note_offset + 5;
		break;
	case 8:
		offset = note_offset + 7;
		break;
	case 11:
		offset = note_offset - 5;
		break;
	default:
		offset = note_offset;
		break;
	}
	return offset;
}

// returns the timestamp at the start of the measure
// measure numbers are zero based
// there are 4 beats in a measure, each beat == 1000ms
uint32_t CInstrument::get_measure_start_time(int meas)
{
	return meas * 4000;
}