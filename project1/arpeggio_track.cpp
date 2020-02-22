#ifndef ARPEGGIO_TRACK_H_
#include "arpeggio_track.h"
#endif

// The random functions have been moved to a utility unit.
#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

ArpeggioTrack::ArpeggioTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                             uint8_t patch, uint8_t volume, uint8_t pan, uint8_t range, std::string pattern, std::vector<std::string> infoVec)
    : CScalesTrack(beginTime, endTime, noteoffset, channel, patch, volume, pan), pat_{pattern}, info_vector_{infoVec}
{
}

// In hindsight, should've broken this function up into way more pieces
void ArpeggioTrack::write_arpeggio_track()
{
  // initialize variables to hold CMidiPacket data
  int time_stamp = get_beginTimestamp();
  uint8_t channel = get_channel();
  // info vector that holds the information from the text file
  std::vector<std::string> info_vector = get_infoVec();
  // pattern that was passed from the command line
  std::string pat = get_pattern();
  // the number of chords will be the size of the info vector - 2
  // because the first two lines contain the tempo and range information
  int num_chords = info_vector.size() - 2;

  for(int i = 0; i < num_chords; i++){ // iterate through each chord
    // identify the note that the chord starts on from the infovec
    std::string chord_substring = info_vector.at(i+2).substr(0,2); // base chord
    // intialize a variable to hold the offset above middle C
    int offset_from_C;
    // 12 iterations at most, since there are 12 notes in an octave
    for(int note_index = 0; note_index < 12; note_index++){ // identifying base note
      // OR statement necessary in conditional because D# = Eb, F# = Gb, etc.
      if(notes_flats.at(note_index) == chord_substring || notes_sharps.at(note_index) == chord_substring){
        offset_from_C = note_index;
        // once we have identified the starting point, we can break from the for loop
        break;
      }
    }

    // the chord modifier is just what type of chord it is (major, minor, or seventh)
    std::string chord_modifier = info_vector.at(i+2).substr(2,1);

    // use the default settings for pan, patch, and volume (could be made more complex later)
    push_pan(0, channel, get_pan());
    push_patch(0, channel, get_patch());
    push_volume(0, channel, get_volume());

    for(int i = 0; i < 4; i++){ // repeat each arpeggio 4 times
      // chord_packets will contain the CMidiPackets for one iteration through the chord
      std::vector<CMidiPacket> chord_packets;

      // initialize a placeholder ts for use in random case
      uint32_t init_ts = time_stamp;
      // for loop to iterate through every octave specified in the range in the text file
      for(int octave_mult = 0; octave_mult < std::stoi(info_vector.at(1)); octave_mult++){
        // 7th chord case
        if(chord_modifier.compare("7") == 0){
          for(int note_hit = 0; note_hit < 4; note_hit++){ // note that 7th chord has 4 notes
            CMP33::CMidiPacket mp = {static_cast<uint32_t>(time_stamp), static_cast<uint8_t>(0x90 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + seventh_chord.at(note_hit)), 127};
            chord_packets.push_back(mp);
            mp = {static_cast<uint32_t>(time_stamp + 499), static_cast<uint8_t>(0x80 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + seventh_chord.at(note_hit)), 0};
            chord_packets.push_back(mp);
            time_stamp += 500;
          }
        }
        // major chord case
        else if(chord_modifier.compare("M") == 0){
          for(int note_hit = 0; note_hit < 3; note_hit++){ // major and minor chords both have 3 notes
            CMP33::CMidiPacket mp = {static_cast<uint32_t>(time_stamp), static_cast<uint8_t>(0x90 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + major_chord.at(note_hit)), 127};
            chord_packets.push_back(mp);
            mp = {static_cast<uint32_t>(time_stamp + 499), static_cast<uint8_t>(0x80 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + major_chord.at(note_hit)), 0};
            chord_packets.push_back(mp);
            time_stamp += 500;
          }
        }
        // default to minor chord case
        else {
          for(int note_hit = 0; note_hit < 3; note_hit++){
            CMP33::CMidiPacket mp = {static_cast<uint32_t>(time_stamp), static_cast<uint8_t>(0x90 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + minor_chord.at(note_hit)), 127};
            chord_packets.push_back(mp);
            mp = {static_cast<uint32_t>(time_stamp + 499), static_cast<uint8_t>(0x80 + channel), static_cast<uint8_t>(60 + offset_from_C + (12*octave_mult) + minor_chord.at(note_hit)), 0};
            chord_packets.push_back(mp);
            time_stamp += 500;
          }
        }
      }
      if(pat.compare("down") == 0){
        std::vector<CMidiPacket> down_vec;
        // iterate backwards through chord_packets, making sure to keep the timestamps correct
        for(int i = chord_packets.size(); i > 0; i--){
          CMP33::CMidiPacket mp = {chord_packets.at(chord_packets.size()-i).get_timestamp(), chord_packets.at(i-1).get_status(), chord_packets.at(i-1).get_data1(), chord_packets.at(i-1).get_data2()};
          down_vec.push_back(mp);
        }      
        chord_packets = down_vec;
      }
      // the timestamps of updown get more complicated, because they add 
      if(pat.compare("updown") == 0){
        std::vector<CMidiPacket> down_vec;
        uint32_t down_ts = chord_packets.at(chord_packets.size()-1).get_timestamp();
        for(int i = 0; i < chord_packets.size()-1; i++){ // essentially the same as backwards, just without the extra top note
          uint8_t down_stat;
          uint8_t down_d2;
          if(i % 2 == 0){
            down_ts += 1;
            down_stat = 0x90 + channel;
            down_d2 = 127;
          }
          else{
            down_ts += 499;
            down_stat = 0x80 + channel;
            down_d2 = 0;
          }
          CMP33::CMidiPacket mp = {down_ts, down_stat, chord_packets.at(chord_packets.size()-2-i).get_data1(), down_d2};
          down_vec.push_back(mp);
        }
        for(auto itr : down_vec){
          chord_packets.push_back(itr);
        }
        time_stamp += 2500;
      }
      // make a whole new notes vector for random, but do get to use get_rand_int
      if(pat.compare("random") == 0){
        std::vector<CMP33::CMidiPacket> random_notes;
        CMidiPacket random_note_NON;
        CMidiPacket random_note_NOF;
        for(int note_hit = 0; note_hit < chord_packets.size()/2; note_hit++){
          random_note_NON = chord_packets.at(get_rand_int(0, (chord_packets.size()/2)-1) * 2);
          random_note_NOF = random_note_NON;
          random_note_NON.set_timestamp(init_ts + (note_hit * 500));
          random_note_NOF.set_timestamp(init_ts+ (note_hit * 500 + 499));
          random_note_NOF.set_status(random_note_NON.get_status() - 0x10);
          random_notes.push_back(random_note_NON);
          random_notes.push_back(random_note_NOF);
        }
        chord_packets = random_notes;
      }
      // just stuffing vtrk in every inner loop
      for(auto itr : chord_packets){
        vtrk.push_back(itr);
      }
    }
  }
}

void ArpeggioTrack::write_track()
{
  // set the patch, volume, and pan
  // Note that it's calling the write_track() function in the parent class
  CScalesTrack::write_track();
  write_arpeggio_track();

  // fill the CMidiPacket vector vtrk that was inherited from CMidiTrack class
  // should be similare to what you did for hw413_CScalesTrack
}