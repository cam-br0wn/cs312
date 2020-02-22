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

    // read in the chord change file
    while (std::getline(inFile, line))
    {
        std::string added_line = std::string(line);
        songInfo.push_back(added_line);
    }
    // by default, use the up pattern, but check the arg for different
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

  // Write the arpeggio track
  arptrack.write_track();
  // create the playback vector vplay
  // use std::copy for arptrack with std::back_inserter(vplay)
  std::vector<CMP33::CMidiPacket> vplay;
  std::copy(arptrack.vtrk.begin(), arptrack.vtrk.end(), std::back_inserter(vplay));

  // vector vplay now holds all elements of arpeggio vector
  // sort vplay vector
  // it will use your operator< (less) routine
  std::sort(vplay.begin(), vplay.end());

  // Set the playback tempo using the previously read in song info from the text file
  CDelayMs::s_tempo = std::stoi(songInfo.at(0));;

  // create the CAppleMidiSynth object
  CAppleMidiSynth ams;
    for (auto itr:vplay){
      ams.send(itr);
    }
}
