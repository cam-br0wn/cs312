// boilerplate here

#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h"
#endif

#include <iostream>

MidiPacket2 create_midipacket2(uint32_t ts, uint8_t st, uint8_t d1){
     MidiPacket2 packet = MidiPacket2();
     packet.timestamp = ts;
     packet.status = st;
     packet.data1 = d1;

     return packet;
}

MidiPacket2 create_midipacket2(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2){
      MidiPacket2 *packet = new MidiPacket2();
      packet->timestamp = ts;
      packet->status = st;
      packet->data1 = d1;
      packet->data2 = d2;

      return *packet;
}

void print_midipacket2(const MidiPacket2 &mp){
  int size = sizeof(mp);
  std::cout << size << std::endl;
  if(mp.data2 != 0){
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << '\t' << std::dec << unsigned(mp.data2) << std::endl;
  }
  else{
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << unsigned(mp.status) << '\t' << std::dec << unsigned(mp.data1) << std::endl;
  }
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1){
  MidiPacket6 *packet = new MidiPacket6();
  packet->timestamp = ts;
  packet->status = st;
  packet->data1 = d1;

  return *packet;
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1, uint16_t d2){
  MidiPacket6 *packet = new MidiPacket6();
  packet->timestamp = ts;
  packet->status = st;
  packet->data1 = d1;
  packet->data2 = d2;

  return *packet;
}

void print_midipacket6(const MidiPacket6 &mp){
  // print_size(mp);
  if(sizeof(mp)){
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << mp.status << '\t' << std::dec << mp.data1 << '\t' << std::dec << mp.data2 << std::endl;
  }
  else{
    std::cout << std::dec << mp.timestamp << '\t' << std::hex << mp.status << '\t' << std::dec << mp.data1 <<  std::endl;
  }
}

int main() {
  // DO NOT CHANGE
  MidiPacket2 mp2 = create_midipacket2(0, 0xc0, 11);
  std::cout << "MidiPacket2: ";
  print_midipacket2(mp2);
  std::cout << "MidiPacket2: ";
  mp2 = create_midipacket2(0, 0x90, 60, 100);
  print_midipacket2(mp2);
  std::cout << "MidiPacket2: ";
  mp2 = create_midipacket2(1000, 0x80, 60, 0);
  print_midipacket2(mp2);

  MidiPacket6 mp6 = create_midipacket6(0, 0xc0, 11);
  std::cout << "MidiPacket6: ";
  print_midipacket6(mp6);
  std::cout << "MidiPacket6: ";
  mp6 = create_midipacket6(0, 0x90, 60, 100);
  print_midipacket6(mp6);
  std::cout << "MidiPacket6: ";
  mp6 = create_midipacket6(1000, 0x80, 60, 0);
  print_midipacket6(mp6);
}
/*
Based on homework 1.3.1 and 1.3.2 which of the eight MidiPacket struct's would you use in your CMidiPacket class?

Defend your choice based on a tradeoff between storage space, ease of output, and compatibility with Apple defining MIDI data as a Byte.

*/