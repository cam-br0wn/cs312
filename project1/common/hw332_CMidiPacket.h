/***************************************************************
 hw322_CMidiPacket.h
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw322
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-01-28
 TIME: 14:45:47
 ***************************************************************/

#ifndef HW332_CMIDIPACKET_H_
#define HW332_CMIDIPACKET_H_

#include <iostream>
#include <string>

namespace CMP33
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
  CMidiPacket &operator=(const CMidiPacket &) = default; // assignment
  // CMidiPacket(const CMidiPacket &);            // copy constructor
  // CMidiPacket &operator=(const CMidiPacket &); // assignment
  CMidiPacket(CMidiPacket &&) = default;            // move constructor
  CMidiPacket &operator=(CMidiPacket &&) = default; // move assignment

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

    /*********************** CMP33 Invariant checks ***********************/
private:
    void ERROR(const std::string& msg) const;  // helper
    void invariant_check() const;
};// end CMidiPacket class
} // end namespace CMP33

const uint32_t kMAX_TIMESTAMP = 1800000; // 30 minutes in milliseconds
const std::string kERR_TIMESTAMP_OUT_OF_RANGE =
        "Timestamp exceeds 30 minutes in milliseconds\n";
const std::string kERR_STATUS_OUT_OF_RANGE =
        "Status out of range. Must be 0x80 - 0xFF\n";
const std::string kERR_DATA1_OUT_OF_RANGE =
        "Data1 out of range. Must be 0 - 127\n";
const std::string kERR_DATA2_OUT_OF_RANGE =
        "Data2 out of range. Must be 0 - 127\n";
const std::string kERR_BAD_8n_MIDIPACKET_LENGTH = "Bad 8n MidiPacket length\n";
const std::string kERR_BAD_9n_MIDIPACKET_LENGTH = "Bad 9n MidiPacket length\n";
const std::string kERR_BAD_An_MIDIPACKET_LENGTH = "Bad An MidiPacket length\n";
const std::string kERR_BAD_Bn_MIDIPACKET_LENGTH = "Bad Bn MidiPacket length\n";
const std::string kERR_BAD_Cn_MIDIPACKET_LENGTH = "Bad Cn MidiPacket length\n";
const std::string kERR_BAD_Dn_MIDIPACKET_LENGTH = "Bad Dn MidiPacket length\n";
const std::string kERR_BAD_En_MIDIPACKET_LENGTH = "Bad En MidiPacket length\n";
const std::string kERR_Fn_MESSAGES_NOT_SUPPORTED =
        "0xFn messages not supported\n";
/*********************** END CMP33 Invariant checks ***********************/

#endif // HW332_CMIDIPACKET_H_
