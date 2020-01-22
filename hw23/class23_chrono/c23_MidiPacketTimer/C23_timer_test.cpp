// C23_timer_test.cpp

#include <iostream>
#include <vector>

#ifndef C23_CTIMER_H_
#include "C23_CTimer.h"
#endif

#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h"
#endif

using namespace CS312; // CTimer

using MidiPacket = MidiPacket2;

void do_reset_print()
{
  // add 1,000,000 MidiPackets to a vector
  std::cout << "No reserve()\n";
  CTimer tm(false);
  std::vector<MidiPacket> v1;
  MidiPacket mp{1000, 0x90, 60, 100};
  for (int ix = 0; ix < 1'000'000; ++ix)
    v1.push_back(mp);
  tm.milli_time();

  // add 1,000,000 MidiPackets to a vector
  // call reserve(oneMillion*sizeof(MidiPacket))
  std::cout << "tm.reset() -> v1.clear() -> reserve()\n";
  tm.reset();
  v1.clear();
  v1.reserve(1'000'000 * sizeof(MidiPacket));
  for (int ix = 0; ix < 1'000'000; ++ix)
    v1.push_back(mp);
  tm.milli_time();
  tm.reset();

  // add 1,000,000 MidiPackets to a vector
  // call reserve(oneMillion*sizeof(MidiPacket))
  std::cout << "v1.clear() -> tm.reset() -> reserve()\n";
  v1.clear();
  tm.reset();
  v1.reserve(1'000'000 * sizeof(MidiPacket));
  for (int ix = 0; ix < 1'000'000; ++ix)
    v1.push_back(mp);
  tm.milli_time();
  tm.reset();

  // add 1,000,000 MidiPackets to a vector
  // call reserve(oneMillion*sizeof(MidiPacket))

  std::cout << "v1.clear() -> reserve() -> tm.reset()\n";
  v1.clear();
  v1.reserve(1'000'000 * sizeof(MidiPacket));
  tm.reset();
  for (int ix = 0; ix < 1'000'000; ++ix)
    v1.push_back(mp);
  tm.milli_time();
  tm.reset();
}

void do_scope_print()
{
  // add 1,000,000 MidiPackets to a vector
  std::cout << "No reserve\n";
  {
    CTimer tm(true);
    std::vector<MidiPacket> v1;

    MidiPacket mp{1000, 0x90, 60, 100};
    for (int ix = 0; ix < 1'000'000; ++ix)
      v1.push_back(mp);
  } //  out of scope, prints when destructor called

  // add 1,000,000 MidiPackets to a vector
  // call reserve(oneMillion*sizeof(MidiPacket))
  std::cout << "CTimer tm -> reserve()\n";
  {
    CTimer tm(true);
    std::vector<MidiPacket> v1;
    v1.reserve(1'000'000 * sizeof(MidiPacket));
    MidiPacket mp{1000, 0x90, 60, 100};
    for (int ix = 0; ix < 1'000'000; ++ix)
      v1.push_back(mp);
  } //  out of scope, prints when destructor called

  // declare before timer created
  // add 1,000,000 MidiPackets to a vector
  // call reserve(oneMillion*sizeof(MidiPacket))
  std::cout << "reserve() -> Create tm\n";
  {
    std::vector<MidiPacket> v1;
    v1.reserve(1'000'000 * sizeof(MidiPacket));
    CTimer tm(true);
    MidiPacket mp{1000, 0x90, 60, 100};
    for (int ix = 0; ix < 1'000'000; ++ix)
      v1.push_back(mp);
  } //  out of scope, prints when destructor called
}

int main()
{
  std::cout << "Time in ms\n";
  std::cout << "==== do_scope_print() ====\n";
  do_scope_print();
  std::cout << "==== do_reset_print() ====\n";
  do_reset_print();
}