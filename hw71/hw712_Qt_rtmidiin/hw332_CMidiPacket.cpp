/***************************************************************
 hw332_CMidiPacket.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw332
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-01-28
 TIME: 14:45:47
 ***************************************************************/

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <iostream>
#include <sstream>
#include <string>

using namespace CMP33;

// the C++ method of initializing constructors is to use a colon
// after the function declaration followed by a comma separated list
// of class data members using curly brace initialization
// the body of the constructor is often empty

// DO NOT CHANGE
CMidiPacket::CMidiPacket()
    : timestamp_{0}, status_{0x80}, data1_{0}, data2_{0}, length_{3}
{
  // empty body
}

CMidiPacket::~CMidiPacket()
{
  // empty body
  // no need to do anything because there was no memory allocation in class
  // Alternatively you could us ~CMidiPacket() = default; in the header file
  // and let the compiler take care of the destructor.
}

// ******************************************************
// FROM HERE TO END YOU HAVE TO IMPLEMENT THESE FUNCTIONS
// ******************************************************
// // copy constructor
// CMidiPacket(const CMidiPacket &rhs)
// {
//   // some info in CPPT2 section 5.2.1
//   // google "c++ copy constructor" on the web.
// }

// // assignment operator
// CMidiPacket &operator=(const CMidiPacket &rhs)
// {
//   // some info in CPPT2 section 5.2.1
//   // google "c++ assignment operator" on the web.
// }

// Constructor for one data byte
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1)
    : timestamp_{ts}, status_{st}, data1_{d1}, length_{2}
{
}

// Constructor for two data bytes
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
    : timestamp_{ts}, status_{st}, data1_{d1}, data2_{d2}, length_{3}
{
}

// Initialize the CMidiPacket data from a string parameter.
// The string is valid MIDIDisplay format.
// Remember status_ is hex without 0x prefix in the string.
// You'll need to find a parsing routine that will
// separate the string into tokens separated by whitespace
// any number of spaces or tabs
// assign the tokens to the data members
// ignore any status_ 0xFn
// remember status_ 0xCn and 0xDn are length_ 2 and do not use data2_
// all other status_ are length_ 3 and use both data1_ and data2_
// assign the length_ once you know the status_
CMidiPacket::CMidiPacket(const std::string &str)
{
  //  tmp uint32_t types
  uint32_t ts = 0;
  uint32_t st = 0;
  uint32_t d1 = 0;
  uint32_t d2 = 0;

  // read timestamp_, status_, and data1_ that are
  // common to all status_ bytes we're working with
  std::istringstream iss(str);
  iss >> std::dec >> ts >> std::hex >> st >> std::dec >> d1;

  // st & 0xF0; the & is bit and
  // example 0xF0 & 0xC7 == 0xC0
  switch (st & 0xF0)
  {
  case 0xC0:
  case 0xD0:
    length_ = 2;
    break;
  case 0x80:
  case 0x90:
  case 0xA0:
  case 0xB0:
  case 0xE0:
    length_ = 3;
    iss >> d2;
    break;
  // we're not going to deal with Fn status_
  default:
    break;
  }
  timestamp_ = ts;
  status_ = static_cast<uint8_t>(st);
  data1_ = static_cast<uint8_t>(d1);
  if (length_ == 3)
  {
    data2_ = static_cast<uint8_t>(d2);
  }
}

// Convert the CMidiPacket data to a string.
// Separate numbers with a single tab char.
// Account for 1 data byte or 2 data byte messages.
// <timestamp_>TAB<status_(hex)>TAB<data1_>
// <timestamp_>TAB<status_-hex>TAB<data1_>TAB<data2_>
// status_ is hex number without 0x prefix.
// length_ should be set at the same time as status_.
// length_ will never be displayed in MIDIDisplay.
// timestamp_, data1_, and data2_ (if used) are decimal numbers.
// send a not processed message if status_ is 0xFn
std::string CMidiPacket::to_string() const
{
  if ((status_ >= 0xF0) && (status_ <= 0xFF))
  {
    return "# 0xFn status_ not processed";
  }

  std::stringstream ss;
  std::string res;
  std::string tab = "\t";
  ss << timestamp_ << tab << std::hex << +status_ << tab << std::dec << +data1_;
  if (length_ == 3)
    ss << tab << +data2_;
  return ss.str();
}

// Do not change print()
// Send a MIDIDisplay string to std::cout
void CMidiPacket::print() const
{
  std::cout << to_string() << std::endl;
}

// getters
uint32_t CMidiPacket::get_timestamp() const
{
  return timestamp_;
}

uint8_t CMidiPacket::get_length() const
{
  return length_;
}

uint8_t CMidiPacket::get_status() const
{
  return status_;
}

uint8_t CMidiPacket::get_data1() const
{
  return data1_;
}

uint8_t CMidiPacket::get_data2() const
{
  return data2_;
}

uint8_t CMidiPacket::get_midi_channel() const
{
  uint8_t st = get_status();
  return st & 0x0F;
}

// setters
void CMidiPacket::set_timestamp(const uint32_t &ts)
{
  timestamp_ = ts;
}

void CMidiPacket::set_status(const uint8_t &st)
{
  status_ = st;
}

void CMidiPacket::set_status_length()
{
  uint8_t statustype = status_ & 0xF0;
  switch (statustype)
  {
  case 0x80:
  case 0x90:
  case 0xA0:
  case 0xB0:
  case 0xE0:
    length_ = 3;
    break;
  case 0xC0:
  case 0xD0:
    length_ = 2;
    break;
  case 0xF0:
    length_ = 0;
    break;
  default:
    //      std::cout << "BAD STATUS LENGTH" << std::endl;
    break;
  }
}

void CMidiPacket::set_data1(const uint8_t &d1)
{
  data1_ = d1;
}

void CMidiPacket::set_data2(const uint8_t &d2)
{
  data2_ = d2;
}

void CMidiPacket::set_midi_channel(const uint8_t &chan)
{
  uint8_t st = get_status() & 0xF0;
  status_ = st + chan;
}

// Utility functions
bool CMidiPacket::is_status_8n() const
{
  if ((status_ & 0xF0) == 0x80)
    return true;
  return false;
}

bool CMidiPacket::is_status_9n() const
{
  if ((status_ & 0xF0) == 0x90)
    return true;
  return false;
}

bool CMidiPacket::is_status_An() const
{
  if ((status_ & 0xF0) == 0xA0)
    return true;
  return false;
}

bool CMidiPacket::is_status_Bn() const
{
  if ((status_ & 0xF0) == 0xB0)
    return true;
  return false;
}

bool CMidiPacket::is_status_Cn() const
{
  if ((status_ & 0xF0) == 0xC0)
    return true;
  return false;
}

bool CMidiPacket::is_status_Dn() const
{
  if ((status_ & 0xF0) == 0xD0)
    return true;
  return false;
}

bool CMidiPacket::is_status_En() const
{
  if ((status_ & 0xF0) == 0xE0)
    return true;
  return false;
}

bool CMidiPacket::is_status_Fn() const
{
  if ((status_ & 0xF0) == 0xF0)
  {
    std::cout << "# 0xFn status_ not processed\n";
    return true;
  }
  return false;
}

bool CMidiPacket::is_note_off() const
{
  if (is_status_8n())
    return true;
  else if (is_status_9n() && data2_ == 0)
    return true;
  else
    return false;
}

bool CMidiPacket::is_note_on() const
{
  if (is_status_9n() && data2_ > 0)
    return true;
  else
    return false;
}

/****************************** FRIENDS ******************************/
// const ref parameter because mp will not be changed
std::ostream &CMP33::operator<<(std::ostream &os, const CMidiPacket &mp)
{
  std::string s;
  s = mp.to_string();
  os << s << std::endl;
  return os;
}

// removed const from mp because mp will be changed when reading from input stream
std::istream &CMP33::operator>>(std::istream &is, CMidiPacket &mp)
{
  std::string s;
  getline(is, s);
  mp = CMidiPacket(s);
  return is;
}

// every member of a must be equal to its counterpart in b
bool CMP33::operator==(const CMidiPacket &a, const CMidiPacket &b)
{
  // return if and only if
  // equivalent data members timestamp_, status_, data1_, data2_, length_
  // match exactly between a and b
  // return true or false
  return (a.timestamp_ == b.timestamp_) && (a.status_ == b.status_) && (a.data1_ == b.data1_) && (a.data2_ == b.data2_);
}

// the most complicated overload in CMidiPacket
// This function will be called repeatedly by sort() until the vector is sorted
bool CMP33::operator<(const CMidiPacket &a, const CMidiPacket &b)
{
  bool is_a_first = false;
  // Sorting rules when timestamps are equal
  // std::cout << "# A " << a << "# B " << b;
  if (a.timestamp_ < b.timestamp_){ // RULE 1
    // lowest timestamp_ always comes first.
    is_a_first = true;
  }


  else if (a.timestamp_ == b.timestamp_) { // RULE 2
    //std::cout << "# (a.timestamp_ == b.timestamp_)\n";
    // NOF comes before anything
    if (a.is_note_off()) {
      switch (b.status_ & 0xF0){
      case 0x90:
      case 0xA0:
      case 0xB0:
      case 0xD0:
      case 0xE0:
        is_a_first = true;
        break;
      case 0x80:
      case 0xC0:
        is_a_first = false;
        break;
      default:
        break;
      }
    }
    // a.status_ == 0x90
    else if (a.is_note_on()) {
      switch (b.status_ & 0xF0) {
          case 0xA0:
          case 0xB0:
          case 0xD0:
          case 0xE0:
              is_a_first = true;
      }
    }

    if (a.is_status_An()) {
      switch (b.status_ & 0xF0){
      
      }
    }

    if (a.is_status_Bn())
    {
      switch (b.status_ & 0xF0) {
         // use all cases 0x80-0xE0
        // decide when a comes before
        // decide when a comes after
      }
    }

    if (a.is_status_Cn()){
        switch (b.status_ & 0xF0){
            case 0x90:
            case 0xA0:
            case 0xB0:
            case 0xD0:
            case 0xE0:
                is_a_first = true;
                break;
            case 0x80:
            case 0xC0:
                is_a_first = false;
                break;
            default:
                break;
        }
    }

    if (a.is_status_Dn()) {
      switch (b.status_ & 0xF0) {
        // use all cases 0x80-0xE0
        // decide when a comes before
        // decide when a comes after
      }
    }

    if (a.is_status_En()) {
      switch (b.status_ & 0xF0) {
        // use all cases 0x80-0xE0
        // decide when a comes before
        // decide when a comes after
      }
    }
  }
  return is_a_first;
}
/********************* END FRIENDS **************************/

/****************************** CMP33 Invariant checking ******************************/
void CMidiPacket::ERROR(const std::string &msg) const
{
    if (1)
    {
        std::cout << "ERROR: " << msg << std::endl;
    }
    else
    {
        throw std::logic_error(msg);
    }
}

void CMidiPacket::invariant_check() const
{
    // range check
    if (timestamp_ > kMAX_TIMESTAMP)
        ERROR(kERR_TIMESTAMP_OUT_OF_RANGE);
    if ((status_ < 0x80) || (status_ >= 0xFF))
        ERROR(kERR_STATUS_OUT_OF_RANGE);
        // data 1 and 2 range check
    else if (data1_ > 0x7F)
        ERROR(kERR_DATA1_OUT_OF_RANGE);
    else if ((data2_ > 0x7F) && length_ == 3)
        ERROR(kERR_DATA2_OUT_OF_RANGE);

        //  status length check
    else if (is_status_8n() && length_ != 3)
        ERROR(kERR_BAD_8n_MIDIPACKET_LENGTH);
    else if (is_status_9n() && length_ != 3)
        ERROR(kERR_BAD_9n_MIDIPACKET_LENGTH);
    else if (is_status_An() && length_ != 3)
        ERROR(kERR_BAD_An_MIDIPACKET_LENGTH);
    else if (is_status_Bn() && length_ != 3)
        ERROR(kERR_BAD_Bn_MIDIPACKET_LENGTH);
    else if (is_status_Cn() && length_ != 2)
        ERROR(kERR_BAD_Cn_MIDIPACKET_LENGTH);
    else if (is_status_Dn() && length_ != 2)
        ERROR(kERR_BAD_Dn_MIDIPACKET_LENGTH);
    else if (is_status_En() && length_ != 3)
        ERROR(kERR_BAD_En_MIDIPACKET_LENGTH);

        //  unsupported check
    else if (is_status_Fn())
        ERROR(kERR_Fn_MESSAGES_NOT_SUPPORTED);
}
/****************************** End CMP33 Invariant checking ******************************/
