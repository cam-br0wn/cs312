// hw422_main.cpp
#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW421_CDELAY_MS_H_
#include "hw421_CDelayMs.h"
#endif

#include <vector>

// Do not modify stuffPackets
void stuffPackets(std::vector<CMidiPacket> &v)
{
  // brute force
  CMidiPacket mp = {0, 0x90, 60, 100}; //C
  v.push_back(mp);                     //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {1000, 0x90, 62, 100}; //D
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {2000, 0x90, 64, 100}; //E
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {3000, 0x90, 65, 100}; //F
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {4000, 0x90, 67, 100}; //G
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {5000, 0x90, 69, 100}; //A
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {6000, 0x90, 71, 100}; //B
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF

  mp = {7000, 0x90, 72, 100}; //C
  v.push_back(mp);            //NON
  mp.set_timestamp(mp.get_timestamp() + 1000);
  mp.set_data2(0);
  v.push_back(mp); //NOF
}
// end Do not modify stuffPackets

int main(int argc, char const *argv[])
{
  // main expects exactly one parameter for tempo
  /*
     display usage message 
     "Usage:\n\thw422_cams <tempo>\n"
      exit not exactly one parameter

     set CDelayMs::s_tempo to argv[1]
     display error message if tempo range is outside 20-300
     exit if tempo is too low or too high
  */


  // stuff packets
  std::vector<CMidiPacket> vplay;
  stuffPackets(vplay);

  // play using CAppleMidiSynth
  CAppleMidiSynth ams;
  ams.send(vplay);

  return 0;
}