// hw622_midiout_cmp33.cpp

//*****************************************//
//  midiout.cpp
//  by Gary Scavone, 2003-2004.
//
//  Simple program to test MIDI output.
//
//  modified for CS312
//*****************************************//

#include <iostream>
#include <cstdlib>

#ifndef RTMIDI_H
#include "RtMidi.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

using namespace CMP33;

RtMidiOut *midiout = 0;
std::vector<CMidiPacket> vplay;

/* Assuming midiprobe returned this
There are 2 MIDI output ports available.
Output Port #0: IAC Driver Bus 1
Output Port #1: DLSMusicDevice
*/
bool chooseMidiPort(RtMidiOut *rtmidi)
{
	rtmidi->openPort(1); // DLSMusicDevice
	return true;
}

void sendCMidiPacket(const CMidiPacket &mp)
{
	// input is CMidiPacket
	// transform to RtMidi message format
	// send using midiout->sendMessage(&message);
	std::cout << "sendCMidiPacket(const CMidiPacket &mp)\n";
	std::cout << "\ttransform to RtMidi message format\n";
	std::cout << "\tsend using midiout->sendMessage(&message)\n";
	std::vector<unsigned char> *message;
	double deltatime;
	// MidiMessage msg;

	message->at(0) = mp.get_status();
	message->at(1) = mp.get_data1();
	message->at(2) = mp.get_data2();
	midiout->sendMessage(msg);
}

void stuffPackets()
{
	// stuff CMidiPacket messages into std::vector<CMidiPacket> vplay
	// create a patch change message for instrument 0, piano
	// create a series of NON and NOF message
	// use all MIDI note numbers 60-72
	// NON timestamps are 0, 1000, 2000, ...
	// NOF timestamps are (NON+900)
	std::cout << "stuffPackets()\n";
	std::cout << "\tstuff CMidiPacket messages into std::vector<CMidiPacket> vplay\n";
	// dummy CMidiPacket
	CMidiPacket mp;
	vplay.push_back(mp);
}

bool openMidiOutPort()
{
	// copy all relevent try_catch blocks out of hw622_rt_midiout main()
	// and use them here
	// return true if port opened
	// return false on any error
	std::cout << "openMidiOutPort()\n";
	std::cout << "\tcopy all relevent try_catch blocks out of hw622_rt_midiout main()\n";
	std::cout << "\tcalls chooseMidiPort(0\n";
	return true;
}

void closeMidiOutPort()
{
	// delete midiout if it exists
	std::cout << "closeMidiOutPort()\n";
	std::cout << "\tdelete midiout if it exists\n";
}

/*========================
   Do not change main()
========================*/
int main()
{
	// OPEN RtMidiOut port
	if (!openMidiOutPort())
		return 0;

	// create vplay vector
	stuffPackets();
	// set tempo
	CDelayMs::s_tempo = 180;
	// play
	for (auto itr : vplay)
		sendCMidiPacket(itr);

	// CLOSE RtMidiOut port
	closeMidiOutPort();

	return 0;
}