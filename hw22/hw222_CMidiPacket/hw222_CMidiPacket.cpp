/***************************************************************
hw132_CMidiPacket.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw222
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/

#ifndef HW222_CMIDIPACKET_H_
#include "hw222_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace CMP22;

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
    // empty body
}

// Default destructor
// Note placement of ~
// no need to do anything because there was no memory allocation in class
// Alternatively you could use ~CMidiPacket() = default in the header file
// and let the compiler implement the destructor.
CMidiPacket::~CMidiPacket()
{
    // empty body
}
// END DO NOT CHANGE

// ******************************************************
// FROM HERE TO END YOU HAVE TO IMPLEMENT THESE FUNCTIONS
// ******************************************************

// Constructor overload for one data byte message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1)
{
    timestamp_ = ts;
    status_ = st;
    data1_ = d1;
    length_ = 2;
}

// Constructor overload for two data bytes message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
{
    timestamp_ = ts;
    status_ = st;
    data1_ = d1;
    data2_ = d2;
    length_ = 3;
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
    std::istringstream ss(str);
    std::string substr;
    std::vector<std::string> strVec;
    while(getline(ss, substr, '\t'))
    {
        strVec.push_back(substr);
    }

    uint32_t time_stamp = std::atoi(strVec.at(0).c_str());
    timestamp_ = time_stamp;

    std::stringstream stat;
    stat << std::hex << strVec.at(1).c_str();
    int status_int;
    stat >> status_int;
    status_ = (uint8_t)status_int;


    uint8_t data_1 = std::atoi(strVec.at(2).c_str());
    data1_ = data_1;

    length_ = strVec.size()-1;

    if(length_ == 3) {
        uint8_t data_2 = std::atoi(strVec.at(3).c_str());
        data2_ = data_2;
    }

}


//  GETTERS
uint32_t CMidiPacket::get_timestamp() const 
{
    return timestamp_;
}
uint8_t CMidiPacket::get_status() const 
{
    return length_;
}
uint8_t CMidiPacket::get_data1() const 
{
    return data1_;
}
uint8_t CMidiPacket::get_data2() const 
{
    return data2_;
}
uint8_t CMidiPacket::get_length() const 
{
    return length_;
}
uint8_t CMidiPacket::get_midi_channel() const 
{
    return length_;
}

 // SETTERS
void CMidiPacket::set_timestamp(const uint32_t &ts) {
    timestamp_ = ts;
}

// status determines the length
void CMidiPacket::set_status(const uint8_t &st) {
  status_ = st;
}
// length cannot be set without knowing status
void CMidiPacket::set_status_length() {
   // if (status ..... )
}

void CMidiPacket::set_data1(const uint8_t &d1) {
    data1_ = d1;
}

void CMidiPacket::set_data1(const uint8_t &d2) {
    data2_ = d2;
}



// void set_midi_channel(const uint8_t &chan);
//  bool is_status_8n() const;
//   bool is_status_9n() const;
//   bool is_status_An() const;
//   bool is_status_Bn() const;
//   bool is_status_Cn() const;
//   bool is_status_Dn() const;
//   bool is_status_En() const;
//   bool is_status_Fn() const;
//   bool is_note_off() const;
//   bool is_note_on() const;































// Convert the CMidiPacket data to a string.
// Separate numbers with a single tab char.
// Account for 1 data byte or 2 data byte messages.
// <timestamp_>TAB<status_(hex)>TAB<data1_>
// <timestamp_>TAB<status_-hex>TAB<data1_>TAB<data2_>
// Status is hex number without 0x prefix.
// Length should be set at the same time as status_.
// Length will never be displayed in a MIDIDisplay message.
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
    ss << std::dec << static_cast<int>(+timestamp_) << tab << std::hex << static_cast<int>(+status_) << tab << std::dec << static_cast<int>(+data1_);
    if (+length_ == 3)
        ss << tab << std::dec << static_cast<int>(+data2_);
    return ss.str();
}

// Do not change print()
// Send a MIDIDisplay string to std::cout using toString()
void CMidiPacket::print() const
{
  std::cout << to_string() << std::endl;
}
