// c512_main.cpp
#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

#ifndef HW511_CBLUESPIANOTRACK_H_
#include "hw511_CBluesPianoTrack.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <vector>

using namespace CMP33;

std::vector<CMidiPacket> vplay;

void write_piano()
{
	uint32_t startTm = 0;
	int scaleOffset = 0;
	int chan = 1;
	int patch = 0; // piano
	int vol = 100;
	int pan = 64; // pan center
	int startNote = 48;
	int meas = 0;

	CBluesPianoTrack pno_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch,
													 vol, pan, startNote, meas);
	pno_trk.write_track();
	// append to vplay
	std::copy(pno_trk.vtrk.begin(), pno_trk.vtrk.end(),
						std::back_inserter(vplay));
}

int main(int argc, char const *argv[])
{
	write_piano();

	CDelayMs::s_tempo = 135;
	CAppleMidiSynth ams;
	ams.send(vplay);

	return 0;
}