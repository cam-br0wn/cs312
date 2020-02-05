// hw421_main.cpp
#ifndef HW421_CDELAY_MS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW332CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

// DO NOT MODIFY THIS FILE

#include <vector>

using namespace CMP33;

std::vector<CMidiPacket> vplay;

void stuffMidiPackets()
{
  // we're going to play an octave of MIDI notes: one a second
  // every NOF and next NON come at intervals of 1000ms
  uint32_t tm{0};
  uint32_t beat_length{0};

  for (int i = 0; i < 13; i++)
  {
    // Note Ons
    beat_length = 1000;
    if (i > 3 && i < 8)
      beat_length = 500;
    else if (i > 10)
      beat_length = 2000;

    CMidiPacket mp(tm, 0x90, 60 + i, 127);
    vplay.push_back(mp);

    // Note Offs
    tm += beat_length;
    mp.set_timestamp(tm); // 0 NOF 1000 NOF 2000 NOF etc
    mp.set_data2(0);
    vplay.push_back(mp);
  }
}

// Instead of playing sound which you'll do later in hw42
// here we're just sending packets to std::cout using timestamp delays
void send(const CMidiPacket &mp)
{
  // a static variable maintains its value between function calls
  // it's needed for calculating the difference between timestamp [n] and [n-1]
  static uint32_t prevTm{0};

  // calculate delay
  uint32_t ms_delay = mp.get_timestamp() - prevTm;
  prevTm = mp.get_timestamp(); // reset prevTm for next fn call

  // create timer delay and send the packet
  CDelayMs timer(ms_delay, true); // true = print time in ms
  std::cout << mp;
}

int main(int argc, char *argv[])
{
  stuffMidiPackets();
  for (auto itr : vplay)
    send(itr);
}