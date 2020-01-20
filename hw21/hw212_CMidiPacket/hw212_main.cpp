/***************************************************************
hw212_main.cpp
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

using namespace CMP21;

int main()
{
	// test the four constructors
    CMidiPacket mp1;
    CMidiPacket mp2{0, 0xc0, 11};
    CMidiPacket mp3{0, 0x90, 67, 100};
    CMidiPacket mp4{"900\t80\t67\t0"};
   CMidiPacket mp5{1000, 0x90, 76, 100};
   CMidiPacket mp6{"1900\t80\t76\t0"};
   CMidiPacket mp7{2000, 0x90, 72, 100};
   CMidiPacket mp8{"2900\t80\t72\t0"};
   CMidiPacket mp9{"3000\tF0\t0"};


    // output messages using print()
   // mp1.print();
    //std::cout << "# length " << + mp1.length << std::endl;
   // mp2.print();
//    std::cout << "# length " << +mp2.length << std::endl;
  //  mp3.print();
//    std::cout << "# length " << +mp3.length << std::endl;
   // mp4.print();
//    std::cout << "# length " << +mp4.length << std::endl;
//    mp5.print();
//    std::cout << "# length " << +mp5.length << std::endl;
//    mp6.print();
//    std::cout << "# length " << +mp6.length << std::endl;
//    mp7.print();
//    std::cout << "# length " << +mp7.length << std::endl;
//    mp8.print();
//    std::cout << "# length " << +mp8.length << std::endl;
//    mp9.print();
//    std::cout << "# length " << +mp9.length << std::endl;
}
