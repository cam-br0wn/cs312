/***************************************************************
hw121_charOutput.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw121
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-15
TIME: 14:46:25
****************************************************************/
#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h"
#endif

#include <iostream>

MidiPacket2 create_midipacket2(uint32_t ts, uint8_t st, uint8_t d1){
     MidiPacket2 packet = MidiPacket2();
     packet.timestamp = ts;
     packet.status = st;
     packet.data1 = d1;
     packet.length = 2;

     return packet;
}

MidiPacket2 create_midipacket2(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2){
      MidiPacket2 *packet = new MidiPacket2();
      packet->timestamp = ts;
      packet->status = st;
      packet->data1 = d1;
      packet->data2 = d2;
      packet->length = 3;

      return *packet;
}

void print_midipacket2(const MidiPacket2 &mp){
  int len = mp.length;

  std::cout << "MidiPacket2 - length  " << len << std::endl;

  if (len == 3) {
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << '\t' << std::dec << unsigned(mp.data2) << std::endl;
  }
  else {
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << std::endl;
  }
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1){
  MidiPacket6 *packet = new MidiPacket6();
  packet->timestamp = ts;
  packet->status = st;
  packet->data1 = d1;
  packet->length = 2;
  return *packet;
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1, uint16_t d2) {
  MidiPacket6 *packet = new MidiPacket6();
  packet->timestamp = ts;
  packet->status = st;
  packet->data1 = d1;
  packet->data2 = d2;
  packet->length = 3;

  return *packet;
}

void print_midipacket6(const MidiPacket6 &mp){

  int len = mp.length;
  std::cout << "MidiPacket6 - length  " << len << std::endl;
  
  if (len == 3) {
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << '\t' << std::dec << unsigned(mp.data2) << std::endl;
  }
  else {
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << std::endl;
  }
}

int main() {
  // DO NOT CHANGE
  MidiPacket2 mp2 = create_midipacket2(0, 0xc0, 11);
  print_midipacket2(mp2);
  mp2 = create_midipacket2(0, 0x90, 60, 100);
  print_midipacket2(mp2);
  mp2 = create_midipacket2(1000, 0x80, 60, 0);
  print_midipacket2(mp2);

  MidiPacket6 mp6 = create_midipacket6(0, 0xc0, 11);
  print_midipacket6(mp6);
  mp6 = create_midipacket6(0, 0x90, 60, 100);
  print_midipacket6(mp6);
  mp6 = create_midipacket6(1000, 0x80, 60, 0);
  print_midipacket6(mp6);
}
/*
Based on homework 1.3.1 and 1.3.2 which of the eight MidiPacket struct's would you use in your CMidiPacket class?
Defend your choice based on a tradeoff between storage space, ease of output, and compatibility with Apple defining MIDI data as a Byte.

We chose to use MidiPacket6 in our CMidiPacket class. Our decision was based off of the range of inputs for each of the fields in a Midi message. 
Besides the timestamp, most of the other values would fit in the range of a 'u_int8 - u_int16' number. We contemplated using MidiPacket2 as well, but 
figured we'd call it safe with the 'u_int16' data types. And, for the timestamp, MidiPacket6 uses an appropriately larger data type: u_int32.  

As far as ease of output, I guess it's harder as you have to handle cases where a packet-struct's doesn't have all its data members assigned values. (ex. data2)

*/