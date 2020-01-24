/***************************************************************
hw22_CMidiPacket.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw222
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/

#ifndef HW221_CMIDIPACKET_H_
#define HW221_CMIDIPACKET_H_

#include <iostream>
#include <string>

namespace CMP22
{
class CMidiPacket
{
private: // not really needed because they're private by default
  // MidiPacket2 data
  uint32_t timestamp_;
  uint8_t status_;
  uint8_t data1_;
  uint8_t data2_;
  uint8_t length_;

public:
  // from class snippet
  CMidiPacket();                                         // constructor
  ~CMidiPacket();                                        // destructor
  CMidiPacket(const CMidiPacket &) = default;            // copy constructor
  CMidiPacket(CMidiPacket &&) = default;                 // move constructor
  CMidiPacket &operator=(const CMidiPacket &) = default; // assignment
  CMidiPacket &operator=(CMidiPacket &&) = default;      // move assignment

  // three overlaoded constructors
  // construct a CMidiPacket for a one data byte message
  CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1);

  // construct a CMidiPacket for a two data byte message
  CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2);

  // construct a CMidiPacket from a valid MIDIDisplay string
  CMidiPacket(const std::string &str);

  // return a string from this CMidiPacket data
  std::string to_string() const;

  // print this CMidiPacket data to std::cout
  // in MIDIDisplay format accounting for message lengths of 2 or 3
  void print() const;

  // getters
  uint32_t get_timestamp() const;
  uint8_t get_status() const;
  uint8_t get_data1() const;
  uint8_t get_data2() const;
  uint8_t get_length() const;
  uint8_t get_midi_channel() const;

  // setters
  void set_timestamp(const uint32_t &ts);
  // status determines the length
  void set_status(const uint8_t &st);
  // length cannot be set without knowing status
  void set_status_length();
  void set_data1(const uint8_t &d1);
  void set_data2(const uint8_t &d2);
  void set_midi_channel(const uint8_t &chan);

  // Utility functions
  bool is_status_8n() const;
  bool is_status_9n() const;
  bool is_status_An() const;
  bool is_status_Bn() const;
  bool is_status_Cn() const;
  bool is_status_Dn() const;
  bool is_status_En() const;
  bool is_status_Fn() const;
  bool is_note_off() const;
  bool is_note_on() const;
};
} // namespace CMP22
#endif // HW221_CMIDIPACKET_H