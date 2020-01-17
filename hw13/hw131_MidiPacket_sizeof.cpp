/***************************************************************
hw121_charOutput.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw121
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-15
TIME: 14:46:25
****************************************************************/
#ifndef HW131_MIDIPACKET_H_
#include "hw131_MidiPacket.h"
#endif

#include <iostream>
#include <string>


// The assignment is to write a template function that will display the size in bytes and bits
// for each of the eight MidiPacket structs using the sizeof() function.
template <typename T>

void print_size(const T &x) {
    int size = sizeof(x);
    std::cout << "bytes: " << size << " bits: " << size * 8 << std::endl;
}

int main() {

    MidiPacket1 mp1 = MidiPacket1();
    MidiPacket2 mp2 = MidiPacket2();
    MidiPacket3 mp3 = MidiPacket3();
    MidiPacket4 mp4 = MidiPacket4();
    MidiPacket5 mp5 = MidiPacket5();
    MidiPacket6 mp6 = MidiPacket6();
    MidiPacket7 mp7 = MidiPacket7();
    MidiPacket8 mp8 = MidiPacket8();

    std::cout << "MidiPacket1 ";
    print_size(mp1); // 7
    std::cout << "MidiPacket2 ";
    print_size(mp2); // 8
    std::cout << "MidiPacket3 ";
    print_size(mp3); // 7
    std::cout << "MidiPacket4 ";
    print_size(mp4); // 8
    std::cout << "MidiPacket5 ";
    print_size(mp5); // 10
    std::cout << "MidiPacket6 ";
    print_size(mp6); // 12
    std::cout << "MidiPacket7 ";
    print_size(mp7); // 12
    std::cout << "MidiPacket8 ";
    print_size(mp8); // 16
}
/*
1. Why do MidiPacket1 and MidiPacket2 report the same size with sizeof()?
A: 

2. Why do MidiPacket3 through MidiPacket6 all report the same size with sizeof()?
A: 

3. Why do MidiPacket7 and MidiPacket8 report the same size with sizeof()?
A: 

4. How do you explain the discrepancy between the number of data members in each of the eight MidiPacket structs and their actual size in memory?
A: The discrepancy is caused by the fact that data members within each packet are not necessarily all 1 byte in size. Some are more, which means 
   that the total sum of bytes required for storing the packet will exceed the number of data members in most if not all cases.
*/
