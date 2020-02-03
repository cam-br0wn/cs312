// hw511_CInstrument.h
#ifndef HW511_INSTRUMENT_H_
#define HW511_INSTRUMENT_H_

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

// DO NOT MODIFY

// Blues form
const int kNUM_MEASURES = 12;
const int kNUM_REPEATS = 1;
const int kTOTAL_MEASURES = kNUM_REPEATS * kNUM_MEASURES;
const int kSONG_END_TIME = kTOTAL_MEASURES * 4000;

class CInstrument : public CMidiTrack
{
private:
	int start_note; // MIDI note offset for pitch 0 in kBLUES_SCALE;
	int meas_num;		// updates measure number as song is playing

public:
	// additional constructor
	CInstrument(uint32_t beginTm, uint32_t endTm, int noteOffset, int chan,
							int patch, int vol, int pan, int startNote, int measNum);

	// getters - defined inline
	int get_start_note() const { return start_note; }
	int get_meas_num() const { return meas_num; }

	// setters - defined inline
	void set_start_note(const int sn) { start_note = sn; };
	void set_meas_num(const int mn) { meas_num = mn; };

	// Utility functions used by melody, piano, and bass classes.
	int get_note_offset(int meas, int note_offset);
	uint32_t get_measure_start_time(int meas);

	// This is a pure virtual function in CMidiTrack
	// and we need to declare it here and define it in CInstrument.cpp
	void write_track() override;

	// write_one_measure is a pure virtual function in CInstrument
	// The sax, piano, and bass subclasses must implement their own versions
	virtual void write_one_measure(int meas, int chan) = 0;
};
#endif // HW511_INSTRUMENT_H_