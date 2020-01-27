/***************************************************************
hw312_CMidiPacket.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw312
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-26
TIME: 23:09:54
****************************************************************/

#ifndef HW312_CMIDIPACKET_H_
#include "hw312_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>

using namespace CMP31;

// the C++ method of initializing constructors is to use a colon
// after the function declaration followed by a comma separated list
// of class data members using curly brace initialization
// the body of the constructor is often empty

// DO NOT CHANGE
// Default constructor
// Initializes a "do nothing" NOF message
CMidiPacket::CMidiPacket()
    : timestamp_{0}, status_{0x80}, data1_{0}, data2_{0}, length_{3}
{
}

// Default destructor
// Note placement of ~
// no need to do anything because there was no memory allocation in class
// Alternatively you could use ~CMidiPacket() = default in the header file
// and let the compiler implement the destructor.
CMidiPacket::~CMidiPacket()
{
}
// END DO NOT CHANGE

// ******************************************************
// FROM HERE TO END YOU HAVE TO IMPLEMENT THESE FUNCTIONS
// ******************************************************

// Constructor overload for one data byte
// use colon initialization
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1)
    : timestamp_{ts}, status_{st}, data1_{d1}, length_{2}
{
}

// Constructor overload for two data bytes
// use colon initialization
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
    : timestamp_{ts}, status_{st}, data1_{d1}, data2_{d2}, length_{3}
{
}

// Constructor overload for string parameter
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

  std::istringstream iss(str);
  iss >> std::dec >> ts >> std::hex >> st >> std::dec >> d1;

  /*
  & is bit AND function 
  st = 0x93 or binary 1001'0011
       0xF0 is binary 1111'0000
  st & 0xF0 is binary 1001'0000 = 0x90
  */
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
  // also if ((status_ & 0xF0) == 0xF0)
  // also if (status_ >> 4 == 0xF)
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
// Send a MIDIDisplay string to std::cout using toString()
void CMidiPacket::print() const
{
  std::cout << to_string() << std::endl;
}

/*===========================================
  The getter, setter, and utility functions 
  will go here when you've completed them.
===========================================*/

#define JE

/****************************** FRIENDS ******************************/
// const ref parameter because mp will not be changed
std::ostream &CMP31::operator<<(std::ostream &os, const CMidiPacket &mp)
{

  os << std::dec << static_cast<int>(mp.timestamp_) << '\t' << std::hex << static_cast<int>(mp.status_) << '\t' << std::dec << static_cast<int>(mp.data1_);
  if (mp.length_ == 3)
  {
    os << '\t' << std::dec << static_cast<int>(mp.data2_);
  }
  os << '\n';
  return os;
}

// removed const from mp because mp will be changed when reading from input stream
std::istream &CMP31::operator>>(std::istream &is, CMidiPacket &mp)
{
    char tab = '\t';
    char* tab_pointer = &tab;
    char new_line = '\n';
    char* new_line_pointer = &new_line;
  is >> std::dec >> mp.timestamp_;
  is >> tab_pointer;
  is >> std::hex >> mp.status_;
  is >> tab_pointer;
  is >> std::dec >> mp.data1_;
  if (mp.length_ == 3)
  {
      is >> tab_pointer;
      is >> std::dec >> mp.data2_;
  }
  is >> new_line_pointer;
  return is;
}

// every member of a must be equal to its counterpart in b
bool CMP31::operator==(const CMidiPacket &a, const CMidiPacket &b)
{
  // return if and only if
  // equivalent data members timestamp_, status_, data1_, data2_, length_
  // match exactly between a and b
  // return true or false
  return (a.timestamp_ == b.timestamp_) && (a.status_ == b.status_) && (a.data1_ == b.data1_) && (a.data2_ == b.data2_);
}

// the most complicated overload in CMidiPacket
// This function will be called repeatedly by sort() until the vector is sorted
bool CMP31::operator<(const CMidiPacket &a, const CMidiPacket &b)
{
  std::cout << "You need to write operator<.\nWe'll save it next class.\n";
  return false;
}

/********************* END FRIENDS **************************/
