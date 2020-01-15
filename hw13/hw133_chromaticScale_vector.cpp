// boilerplate here

#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h" // reuse from hw132
#endif

#include <iostream>
#include <string>
#include <vector>

std::vector<MidiPacketX> vec;

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
}

void print_chromatic_scale()
{
  // for every element in vec
  // print the MIDIDisplay message with numbers separated by a tab character
  std::cout << "You can do better." << std::endl;
  for (int ix = 1; ix < 5; ++ix)
  {
    std::cout << "note " << ix << std::endl;
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