// boilerplate here

#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h"
#endif

#include <iostream>

MidiPacket2 create_midipacket2(uint32_t ts, uint8_t st, uint8_t d1){
     MidiPacket2 *packet = new MidiPacket2();
     packet->timestamp = ts;
     packet->status = st;
     packet->data1 = d1;

     return *packet;
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
 // print_size(mp);
  std::cout << mp.timestamp << '\t' << mp.status << '\t' << mp.data1 << '\t' <<  std::endl;
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1){
}

MidiPacket6 create_midipacket6(uint32_t ts, uint16_t st, uint16_t d1, uint16_t d2){
}

void print_midipacket6(const MidiPacket6 &mp){
  // you write
}

int main() {
  // DO NOT CHANGE
  MidiPacket2 mp2 = create_midipacket2(0, 0xc0, 11);
  print_midipacket2(mp2);
//   mp2 = create_midipacket2(0, 0x90, 60, 100);
//   print_midipacket2(mp2);
//   mp2 = create_midipacket2(1000, 0x80, 60, 0);
//   print_midipacket2(mp2);

//   MidiPacket6 mp6 = create_midipacket6(0, 0xc0, 11);
//   print_midipacket6(mp6);
//   mp6 = create_midipacket6(0, 0x90, 60, 100);
//   print_midipacket6(mp6);
//   mp6 = create_midipacket6(1000, 0x80, 60, 0);
//   print_midipacket6(mp6);
}