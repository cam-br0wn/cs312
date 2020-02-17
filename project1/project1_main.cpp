#ifndef ARPEGGIO_TRACK_H_
#include "arpeggio_track.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW421_CDELAY_MS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

int main(int argc, char const *argv[])
{
    std::vector<std::string> songInfo;
    std::string line;
    std::ifstream inFile("chordChanges.txt");

    // uint16_t beginTime = 0;
    // uint16_t endTime = 60000;
    // uint16_t startNote = 72;
    // uint16_t chan = 0;
    // uint16_t patch = 15;
    // uint16_t vol = 90;
    // uint16_t pan = 63;

    while (std::getline(inFile, line))
    {
        std::string added_line = std::string(line);
        songInfo.push_back(added_line);
    }
    ArpeggioTrack arptrack(0,0,0,1,1,127,63,1,"up",songInfo);
    if(strcmp("down", argv[2]) == 0){
      arptrack = {0,0,0,1,1,127,63,1,"down",songInfo};
    }
    else if(strcmp("updown", argv[2]) == 0){
      arptrack = {0,0,0,1,1,127,63,1,"updown",songInfo};
    }
    else if(strcmp("random", argv[2]) == 0){
      arptrack = {0,0,0,1,1,127,63,1,"random",songInfo};
    }

  // Write the three tracks
  arptrack.write_track();
  // create the playback vector vplay
  // use std::copy for sop_trk, alto_trk, bass_trk with std::back_inserter(vplay)
  std::vector<CMP33::CMidiPacket> vplay;
  // for(auto itr : arptrack.vtrk){
  //   std::cout << itr;
  // }
  std::copy(arptrack.vtrk.begin(), arptrack.vtrk.end(), std::back_inserter(vplay));

  // vector vplay now holds all elements of sop, alto, bass vectors
  // sort vplay vector
  // it will use your operator< (less) routine
  std::sort(vplay.begin(), vplay.end());

  // Set the playback tempo
  // This is the variable you use
  // The number (120) is passed in from the command line
//  CDelayMs::s_tempo = std::atoi(argv[1]);
  int tempo = std::stoi(songInfo.at(0));
  CDelayMs::s_tempo = tempo;
  // create the CAppleMidiSynth object
  CAppleMidiSynth ams;
    for (auto itr:vplay){
      std::cout << itr;
      ams.send(itr);
    }
}
