/***************************************************************
hw121_charOutput.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw121
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

/*** D O   N O T    M O D I F Y ***/

#ifndef HW131_MIDIPACKET_H_
#define HW131_MIDIPACKET_H_

#include <cstdint> // for uintN_t types

struct MidiPacket1
{
  // size in bytes 4+1+1+1 = 7
  uint32_t timestamp;
  uint8_t status;
  uint8_t data1;
  uint8_t data2;
};

struct MidiPacket2
{
  // size in bytes 4+1+1+1+1 = 8
  uint32_t timestamp;
  uint8_t status;
  uint8_t data1;
  uint8_t data2;
  uint8_t length;
};

struct MidiPacket3
{
  // size in bytes 1+4+1+1 = 7
  uint8_t status;
  uint32_t timestamp;
  uint8_t data1;
  uint8_t data2;
};

struct MidiPacket4
{
  // size in bytes 1+1+4+1+1= 8
  uint8_t status;
  uint32_t timestamp;
  uint8_t data1;
  uint8_t data2;
  uint8_t length;
};

struct MidiPacket5
{
  // size in bytes 4+2+2+2 = 10
  uint32_t timestamp;
  uint16_t status;
  uint16_t data1;
  uint16_t data2;
};

struct MidiPacket6
{
  // size in bytes 4+2+2+2+2 = 12
  uint32_t timestamp;
  uint16_t status;
  uint16_t data1;
  uint16_t data2;
  uint16_t length;
};

struct MidiPacket7
{
  // size in bytes 8+1+1+1+1 = 12
  uint64_t timestamp;
  uint8_t status;
  uint8_t data1;
  uint8_t data2;
  uint8_t length;
};

struct MidiPacket8
{
  // size in bytes 8+2+2+2+2 = 16
  uint64_t timestamp;
  uint16_t status;
  uint16_t data1;
  uint16_t data2;
  uint16_t length;
};


struct MidiPacket9
{
  // size in bytes 8+4+4+4+4 = 24
  uint64_t timestamp;
  int status;
  int data1;
  int data2;
  int length;
};



#endif // HW132_MIDIPACKET_H_