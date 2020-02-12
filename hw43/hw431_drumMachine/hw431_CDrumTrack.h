/***************************************************************
hw431_CDrumTrack.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw431
Brown Cam brownc2@carleton.edu
Stritzel Matt stritzelm@carleton.du
DATE: 2020-02-12
TIME: 12:38:21
****************************************************************/
#ifndef hw431_CDRUMTRACK_H_
#define hw431_CDRUMTRACK_H_

#ifndef hw423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#include <iostream>
#include <string>
#include <cstdint>

// DO NOT MODIFY

class CDrumTrack : public CMidiTrack
{
private:
  uint8_t drum_note;
  std::vector<std::string> vbeat_pattern;
  std::vector<uint32_t> vbeat_dur;

  void write_onebeat(std::string pat);
  void write_beats();

public:
  int beat_num;

  CDrumTrack();
  virtual ~CDrumTrack() = default;
  CDrumTrack(const CDrumTrack &) = default;
  CDrumTrack(CDrumTrack &&) = default;
  CDrumTrack &operator=(const CDrumTrack &) = default;
  CDrumTrack &operator=(CDrumTrack &&) = default;

  void init_note_pats(const uint8_t note, const std::vector<std::string> &pats);

  int getDrumNote() const { return drum_note; }
  void setDrumNote(const int &n) { drum_note = n; };
  int getBeatNum() const { return beat_num; }
  void setBeatNum(const int &m) { beat_num = m; };

  void write_track();
  void write_track(int num_loops);
};

#endif // hw431_CDRUMTRACK_H_