// boilerplate here

#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h" // reuse from hw132
#endif

#include <iostream>
#include <string>
#include <vector>

std::vector<MidiPacket6> vec;

void stuff_chromatic_scale_vector(int start_note, int end_note)
{
  const int kNON_DELTA_TIME = 250; // time between NON's
  const int kNON_DURATION = 200;
  // *** pseudo code ***
  // create a variable tsNON to hold the value of the current NON timestamp
  // set tsNON = 0
  // create a FOR LOOP indexed from 0 to the total number of notes minus one
  // create the NON message (tsNON status note velocity)
  // stuff into vec (std::vector<MidiPacketX> above)
  // calculate timestamp for the matching NOF MIDI message
  // stuff into vec (timestamp status note velocity)
  // increment tsNON
  // next iteration of for loop
  uint32_t tsNON = 0;
  for (int ix = 0; ix < end_note - start_note + 1; ++ix){

    MidiPacket6 mp6NON = MidiPacket6();
    mp6NON.timestamp = tsNON;
    mp6NON.status = 0x90;
    mp6NON.data1 = start_note + ix;
    mp6NON.data2 = 100;
    vec.insert(vec.begin(), mp6NON);

    MidiPacket6 mp6NOF = MidiPacket6();
    mp6NOF.timestamp = tsNON + kNON_DURATION;
    mp6NOF.status = 0x80;
    mp6NOF.data1 = start_note + ix;
    mp6NOF.data2 = 0;
    vec.insert(vec.begin(), mp6NOF);

    tsNON += kNON_DELTA_TIME;
  }
}

void print_chromatic_scale()
{
  // for every element in vec
  // print the MIDIDisplay message with numbers separated by a tab character
  std::cout << "You can do better." << std::endl;
  for (int ix = vec.size()-1; ix >= 0; --ix)
  {
    std::cout << std::dec << vec[ix].timestamp << '\t' << std::hex << vec[ix].status << '\t' << std::dec << vec[ix].data1 << '\t' << std::dec << vec[ix].data2 << std::endl;
    // std::cout << std::dec << vec[ix-1].timestamp << '\t' << std::hex << vec[ix-1].status << '\t' << std::dec << vec[ix-1].data1 << '\t' << std::dec << vec[ix-1].data2 << std::endl;
  }
}

int main()
{
  // DO NOT CHANGE
  stuff_chromatic_scale_vector(48, 72);
  print_chromatic_scale();
  // play in MIDIDisplay to test
  // debug as needed
}
/*

*/