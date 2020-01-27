/***************************************************************
hw312_CMidiPacket.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw312
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-26
TIME: 23:09:54
****************************************************************/

#ifndef HW312_CMIDIPACKET_H_
#define HW312_CMIDIPACKET_H_

#include <iostream>
#include <string>

namespace CMP31
{
class CMidiPacket
{
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

  /*===========================================
  The getter, setter, and utility functions 
  will go here when you've completed them.
===========================================*/

  // NEW FOR hw312_CMidiPacket
  /****************************** FRIENDS ******************************/
  // operator<< for output
  friend std::ostream &operator<<(std::ostream &os, const CMidiPacket &mp);
  // operator<< for input
  friend std::istream &operator>>(std::istream &is, CMidiPacket &mp);
  // operator== for testing equality
  friend bool operator==(const CMidiPacket &a, const CMidiPacket &b);
  // operator< for testing less_than for MidiPackets
  friend bool operator<(const CMidiPacket &a, const CMidiPacket &b);
  /****************************** END FRIENDS ******************************/

};
} // namespace CMP31
#endif // HW212_CMIDIPACKET_H_
