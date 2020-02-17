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
#include <unistd.h>
#define SLEEP(milliseconds) usleep((unsigned long)(milliseconds * 1000.0))

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
	unsigned int nPorts = rtmidi->getPortCount();
	rtmidi->openPort(1); // DLSMusicDevice  
	return true;
}

void sendCMidiPacket(const CMidiPacket &mp)
{
	// input is CMidiPacket
	// transform to RtMidi message format
	// send using midiout->sendMessage(&message);

	std::vector<unsigned char> message;

	static uint32_t prevTm{0};
	uint32_t nowTm = mp.get_timestamp();
	// uint32_t ms_delay = mp.get_timestamp() - prevTm;
	// uint32_t ms_delay = mp.get_timestamp() - prevTm;
	uint32_t deltatime = (nowTm - prevTm);
	CDelayMs d(deltatime, false);

	message.push_back(mp.get_status());
	message.push_back(mp.get_data1());
	if (mp.get_length() == 3)
	{
		message.push_back(mp.get_data2());
	}

	midiout->sendMessage(&message); 
	prevTm = nowTm;
}

void stuffPackets()
{
	// stuff CMidiPacket messages into std::vector<CMidiPacket> vplay
	// create a patch change message for instrument 0, piano
	// create a series of NON and NOF message
	// use all MIDI note numbers 60-72
	// NON timestamps are 0, 1000, 2000, ...
	// NOF timestamps are (NON+900)
	// dummy CMidiPacket

	CMidiPacket mp{0, 0xC0, 0};
	vplay.push_back(mp);
	for (int i = 0; i < 13; i++)
	{
		mp = {static_cast<uint32_t>((1000 * i)), 0x90, static_cast<uint8_t>(60 + i), 100};
		vplay.push_back(mp);
		mp = {static_cast<uint32_t>((1000 * i) + 900), 0x80, static_cast<uint8_t>(60 + i), 0};
		vplay.push_back(mp);
	}
}

bool openMidiOutPort()
{
	// copy all relevent try_catch blocks out of hw622_rt_midiout main()
	// and use them here
	// return true if port opened
	// return false on any error
	// RtMidiOut constructor
	try
	{
		midiout = new RtMidiOut();
		std::cout << "Created midiout successfully" << std::endl;
	}
	catch (RtMidiError &error)
	{
		error.printMessage();
		exit(EXIT_FAILURE);
	}

	// Call function to select port.

	try
	{
		if (chooseMidiPort(midiout) == false) 

			goto cleanup;
	}
	catch (RtMidiError &error)
	{
		error.printMessage();
		goto cleanup;
	}

	return true;

	
cleanup:

	delete midiout;
	return false;
}

void closeMidiOutPort()
{
	// delete midiout if it exists
	midiout->closePort();
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
	{
		sendCMidiPacket(itr);
	}

	// CLOSE RtMidiOut port
	closeMidiOutPort();

	return 0;
}
