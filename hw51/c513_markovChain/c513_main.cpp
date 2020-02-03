// c513_main.cpp
#ifndef CMARKOVBLUES_H_
#include "CMarkovBlues.h"
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <random>

int startNote{0};
bool isStartSet = false;

const std::vector<int> vscale{0, 3, 4, 7, 9, 10, 12}; // rock blues

void play_melody(std::vector<int> v)
{
	CDelayMs::s_tempo = 74;
	CMidiPacket mp;
	std::vector<CMidiPacket> vplay;
	uint32_t tm{0};
	for (int ix = 0; ix < v.size(); ++ix)
	{
		// NON
		uint8_t note = v.at(ix);
		{
			mp = {tm, 0x90, note, 100};
			if (ix % 2 == 0)
			{
				tm += 667;
				mp.set_data2(120);
			}
			else
			{
				tm += 333;
				mp.set_data2(85);
			}
			vplay.push_back(mp);

			// NOF
			mp = {tm - 1, 0x80, note, 0};
			vplay.push_back(mp);
		}
	}

	CAppleMidiSynth ams;
	ams.send(vplay);
	CDelayMs d(1000, false);
}

void gen_random_melody(const int numNotes)
{
	std::vector<int> vec;
	std::vector<int> vi;

	// vec.clear();
	// vi.clear();

	for (auto n = 0; n < numNotes; ++n)
	{
		// reset note for the next time through the inner loop
		int ni = get_rand_int(0, vscale.size() - 1);
		if (!isStartSet)
		{
			startNote = vscale.at(ni);
			isStartSet = true;
		}
		int note = vscale.at(ni) + 60;
		vec.push_back(note);
		vi.push_back(ni);
	}
	isStartSet = false;

	std::cout << "==== random_melody ====\n";
	for (auto itr : vi)
	{
		std::cout << vscale.at(itr) << " ";
	}
	std::cout << std::endl;
	play_melody(vec);
}

void gen_markov_melody(const int numNotes)
{
	// std::cout << "==== gen_markov_melody ====\n";
	CMarkovBlues mb;
	std::vector<int> vec;
	std::vector<int> vi;

	vec.clear();
	vi.clear();
	int note = startNote;
	// Inner for loop
	for (auto n = 0; n < numNotes; ++n)
	{
		// reset note for the next time through the inner loop
		if (n == 0)
			note = startNote;
		else
		{
			// This statement chooses the next note based on the previous one
			// note = mb.chooseMarkovNote(note);

			// This statement chooses all notes based on the starting note
			// that was set as the first starting note of the random melody
			note = mb.chooseMarkovNote(startNote);
		}
		vec.push_back(note + 60);
	}

	std::cout << "==== markov_melody ====\n";
	for (auto itr : vec)
	{
		std::cout << itr - 60 << " ";
	}
	std::cout << std::endl;
	play_melody(vec);
}

int main(int argc, char const *argv[])
{
	const int kNUM_NOTES = 8; // number of notes to generate
	const int kNUM_TESTS = 4; // number of experiments

	for (int i = 0; i < kNUM_TESTS; ++i)
	{
		gen_random_melody(kNUM_NOTES);
		// std::cout << std::endl;

		gen_markov_melody(kNUM_NOTES);
		std::cout << std::endl;
	}
	return 0;
}