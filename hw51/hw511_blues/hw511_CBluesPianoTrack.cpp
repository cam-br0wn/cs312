/***************************************************************
hw511_CBluesPianoTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef HW511_CBLUESPIANOTRACK_H_
#include "hw511_CBluesPianoTrack.h"
#endif

struct ChordTm
{
	int note1;
	int note2;
	int note3;
	int note4;
	int dur;
};

// rock blues scale
ChordTm chord1{3, 7, 10, 12, 1500};
ChordTm chord2{7, 10, 12, 15, 2000}; // {7, 10, 12, 3+12}
ChordTm chord3{3, 7, 10, 12, 2500};

const std::vector<ChordTm> one_meas_chord_vec = {chord1, chord2, chord3};

// additional constructor
CBluesPianoTrack::CBluesPianoTrack(uint32_t beginTm, uint32_t endTm,
																	 int scaleOffset, int chan, int patch,
																	 int vol, int pan, int startNote, int meas)
		: CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
									meas) {}

void CBluesPianoTrack::write_one_measure(int meas, int chn)
{
	CMidiPacket mp;

	uint16_t offset = get_note_offset(meas, get_start_note());
	uint32_t meas_tm = get_measure_start_time(meas);
	for (auto itr : one_meas_chord_vec)
	{
		push_non(meas_tm + itr.dur, chn, itr.note1 + offset, 127);
		push_non(meas_tm + itr.dur, chn, itr.note2 + offset, 127);
		push_non(meas_tm + itr.dur, chn, itr.note3 + offset, 127);
		push_non(meas_tm + itr.dur, chn, itr.note4 + offset, 127);

		push_nof(meas_tm + 300 + itr.dur, chn, itr.note1 + offset);
		push_nof(meas_tm + 300 + itr.dur, chn, itr.note2 + offset);
		push_nof(meas_tm + 300 + itr.dur, chn, itr.note3 + offset);
		push_nof(meas_tm + 300 + itr.dur, chn, itr.note4 + offset);
	}
	set_meas_num(get_meas_num() + 1);
}