// hw212_CMidiPacket.cpp

#ifndef HW212_CMIDIPACKET_H_
#include "hw212_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace CMP21;

// the C++ method of initializing constructors is to use a colon
// after the function declaration followed by a comma separated list
// of class data members using curly brace initialization
// the body of the constructor is often empty

// DO NOT CHANGE
// Default constructor
// Initializes a "do nothing" NOF message
CMidiPacket::CMidiPacket()
    : timestamp{0}, status{0x80}, data1{0}, data2{0}, length{3}
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
}

// Constructor overload for two data bytes message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
{
}

// Constructor overload for string parameter
// Initialize the CMidiPacket data from a string parameter.
// The string is valid MIDIDisplay format.
// Remember status is hex without 0x prefix in the string.
// You'll need to find a parsing routine that will
// separate the string into tokens separated by whitespace
// any number of spaces or tabs
// assign the tokens to the data members
// ignore any status 0xFn
// remember status 0xCn and 0xDn are length 2 and do not use data2
// all other status are length 3 and use both data1 and data2
// assign the length once you know the status
CMidiPacket::CMidiPacket(const std::string &str)
{
}

// Convert the CMidiPacket data to a string.
// Separate numbers with a single tab char.
// Account for 1 data byte or 2 data byte messages.
// <timestamp>TAB<status(hex)>TAB<data1>
// <timestamp>TAB<status-hex>TAB<data1>TAB<data2>
// Status is hex number without 0x prefix.
// Length should be set at the same time as status.
// Length will never be displayed in a MIDIDisplay message.
// timestamp, data1, and data2 (if used) are decimal numbers.
// send a not processed message if status is 0xFn
std::string CMidiPacket::to_string() const
{
  // need to return a string to avoid compile error
  return "You need to implement CMidiPacket::to_string()";
}

// Do not change print()
// Send a MIDIDisplay string to std::cout using toString()
void CMidiPacket::print() const
{
  std::cout << to_string() << std::endl;
}