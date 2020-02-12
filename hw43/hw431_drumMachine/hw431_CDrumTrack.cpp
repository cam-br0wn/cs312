// hw431_CDrumTrack.cpp
#ifndef hw431_CDRUMTRACK_H_
#include "hw431_CDrumTrack.h"
#endif

CDrumTrack::CDrumTrack() : CMidiTrack(0, 0, 0, 0, 0, 0, 0)
{
  drum_note = 0;
  vbeat_pattern = {"0000", "0000", "0000", "0000"};
  vbeat_dur = {250, 250, 250, 250};
  beat_num = 0;
}

void CDrumTrack::init_note_pats(const uint8_t note, const std::vector<std::string> &pats)
{
  drum_note = note;
  vbeat_pattern = {pats};
}

void CDrumTrack::write_onebeat(std::string pat)
{
  for (int i = 0; i < pat.length(); i++) { // should be 4

    //CMidiPacket 
//     u_int32_t timestamp = 1000 * beat_num;

    if (pat[i] == '1') {
        push_non(beat_num * 250, 0x9, drum_note, 127);
        push_nof((beat_num * 250) + 249, 0x9, drum_note);
    }
    beat_num++;
  }

  /* 
  beat_num keeps a running count of the drum_machine ticks.
  In one trip through a drum_machine row, beat_num's will be 0, 1, 2, ... 14, 15
  In four trips through a drum_machine row, the starting beat_num of each repeat will be 0, 16, 32, 48
  The timestamp of each beat_num = beat_num * 1000
  vbeat_dur is a vector of 4 timestamps representing the duration of each beat subdivision {250,250,250,250}
  vbeat_pattern is a vector of 4 strings representing the on/off state of each beat subdivision {"1000","1000","1000","1000"}
  pat is one element of the vbeat_pattern vector representing the four subdivisions of a single beat like "1010".
  vbeat_dur.size() == vbeat_pattern.size() == 4 elemenets in each vector
  pat.size() == 4 (each element of vbeat_pattern has string length == 4)
  Every "1" in pat sends a NON message and must be matched with a n NOF 1ms before the next beat subdivision starts.
  Every "0" in pat is ignored for NON/NOF 
  The timestamp of each beat subdivision is updated by its duration for both "1" and "0".
  Increment beat_num when all four ones and zeros of the beat subdivision have been processed
 */
}

void CDrumTrack::write_beats()
{
  int subdivs = vbeat_pattern.size(); // is always be 4 for this drum machine
  for (int ix = 0; ix < subdivs; ++ix)
    write_onebeat(vbeat_pattern.at(ix));
}

void CDrumTrack::write_track()
{
    write_beats();    // write_beats for that column
    if(beat_num == 15){
        beat_num = 0;
    }
}

void CDrumTrack::write_track(int num_loops)  // loop col by col
{
  for (auto ix = 0; ix < num_loops; ++ix)
    write_track();
}
