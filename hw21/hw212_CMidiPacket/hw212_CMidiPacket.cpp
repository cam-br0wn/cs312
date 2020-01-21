/***************************************************************
hw132_CMidiPacket.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw212
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/

#ifndef HW212_CMIDIPACKET_H_
#include "hw212_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

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
    // Ex. CMidiPacket mp2{0, 0xc0, 11};
    CMidiPacket packet = CMidiPacket();
    packet.timestamp = ts;
    packet.status = st;
    packet.data1 = d1;
    packet.length = 2;
//    std::cout << packet.timestamp << '\t' << std::to_string(packet.status) << '\t' << std::to_string(packet.data1) << '\t' << std::endl;
}

// Constructor overload for two data bytes message
// use colon initialization with parameters inside curly braces
CMidiPacket::CMidiPacket(uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
{
    // Ex. CMidiPacket mp3{0, 0x90, 67, 100};
    CMidiPacket packet = CMidiPacket();
    packet.timestamp = ts;
    packet.status = st;
    packet.data1 = d1;
    packet.data2 = d2;
    packet.length = 3;

//     std::cout << packet.timestamp << '\t' << std::to_string(packet.status) << '\t' << std::to_string(packet.data1) << '\t' << std::to_string(packet.data2) << std::endl;
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
    CMidiPacket packet = CMidiPacket();
    std::istringstream ss(str);
    std::string substr;
    std::vector<std::string> strVec;
    while(getline(ss, substr, '\t'))
    {
        strVec.push_back(substr);
    }

    uint32_t time_stamp = std::atoi(strVec.at(0).c_str());
    packet.timestamp = time_stamp;

    // Not sure if this is returning the proper value, but best attempt
    std::stringstream stat;
    stat << std::hex << strVec.at(1).c_str();
    int status_int;
    stat >> status_int;
    packet.status = (uint8_t)status_int;


    uint8_t data_1 = std::atoi(strVec.at(2).c_str());
    packet.data1 = data_1;

    packet.length = strVec.size()-1;

    if(packet.length == 3) {
        uint8_t data_2 = std::atoi(strVec.at(3).c_str());
        packet.data2 = data_2;
    }

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
    if ((status >= 0xF0) && (status <= 0xFF))
    {
        return "# 0xFn status_ not processed";
    }

    std::stringstream ss;
    std::string res;
    std::string tab = "\t";
    ss << std::dec << static_cast<int>(timestamp) << tab << std::hex << static_cast<int>(status) << tab << std::dec << static_cast<int>(data1);
    if (length == 3)
        ss << tab << std::dec << static_cast<int>(data2);
    return ss.str();
}

// Do not change print()
// Send a MIDIDisplay string to std::cout using toString()
void CMidiPacket::print() const
{
    std::cout << to_string() << std::endl;
}
