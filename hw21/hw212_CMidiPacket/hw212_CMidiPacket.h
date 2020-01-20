/***************************************************************
hw212_CMidiPacket.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw212
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/

#ifndef HW212_CMIDIPACKET_H_
#define HW212_CMIDIPACKET_H_

#include <iostream>
#include <string>

namespace CMP21
{
class CMidiPacket
{
public:
	// MidiPacket2 data
	uint32_t timestamp;
	uint8_t status;
	uint8_t data1;
	uint8_t data2;
	uint8_t length;

	// from class snippet
	CMidiPacket();																				 // constructor
	~CMidiPacket();																				 // destructor
	CMidiPacket(const CMidiPacket &) = default;						 // copy constructor
	CMidiPacket(CMidiPacket &&) = default;								 // move constructor
	CMidiPacket &operator=(const CMidiPacket &) = default; // assignment
	CMidiPacket &operator=(CMidiPacket &&) = default;			 // move assignment

	// three overlaoded constructors
	// construct a CMidiPacket for a one data byte message
	CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1);

	// construct a CMidiPacket for a two data byte message
	CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2);

	// construct a CMidiPacket from a valid MIDIDisplay string
	CMidiPacket(const std::string &str);

	// return a string from this CMidiPacket data
	std::string to_string() const;

	// print this CMidiPacket data to std::cout
	// in MIDIDisplay format accounting for message lengths of 2 or 3
	void print() const;
};
} // namespace CMP21
#endif // HW212_CMIDIPACKET_H_