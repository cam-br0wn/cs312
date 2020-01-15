// boilerplate here

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

    MidiPacket1 *mp1 = new MidiPacket1();
    MidiPacket2 *mp2 = new MidiPacket2();
    MidiPacket3 *mp3 = new MidiPacket3();
    MidiPacket4 *mp4 = new MidiPacket4();
    MidiPacket5 *mp5 = new MidiPacket5();
    MidiPacket6 *mp6 = new MidiPacket6();
    MidiPacket7 *mp7 = new MidiPacket7();
    MidiPacket8 *mp8 = new MidiPacket8();

    print_size(mp1);
    print_size(mp2);
    print_size(mp3);
    print_size(mp4);
    print_size(mp5);
    print_size(mp6);
    print_size(mp7);
    print_size(mp8);
}