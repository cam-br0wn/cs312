/***************************************************************
hw234_scifiSounds.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw234
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-23
TIME: 7:38:20
****************************************************************/

#ifndef HW234_SCIFISOUNDS_H_
#include "hw234_scifiSounds.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace CMP22;

std::vector<CMidiPacket> scifi_vec;

void create_scifisounds_vector(int start_note, int end_note)
{

	const int kNON_DELTA_TIME = 500; // time between NON's
	const int kNON_DURATION = 100;	 // time NOF appears after NON

	for(int i = 0; i < 100; i++){

        int random_pitch = rand() % 13;
        int random_patch = rand() % 10;
		
		int timestamp_NON = i * kNON_DELTA_TIME;
		int timestamp_NOF = timestamp_NON + kNON_DURATION;
		uint8_t status_patch = 0xc0;
        uint8_t status_NON = 0x90;
		uint8_t status_NOF = 0x80;
		int data1 = 60 + random_pitch;
        int data1_patch = random_patch;
		int data2_NON = 100;
		int data2_NOF = 0;
        CMidiPacket mp_patch_change(timestamp_NON, status_patch, data1_patch);
		CMidiPacket mp_NON(timestamp_NON, status_NON, data1, data2_NON);
		CMidiPacket mp_NOF(timestamp_NOF, status_NOF, data1, data2_NOF);
        scifi_vec.push_back(mp_patch_change);
		scifi_vec.push_back(mp_NON);
		scifi_vec.push_back(mp_NOF);
	}
}

void print_scifi()
{
	for(int i = 0; i < scifi_vec.size(); i++){
        std::stringstream ss;
		std::string res;
		std::string tab = "\t";
        if(i % 3 == 0){
            ss << std::dec << static_cast<int>(scifi_vec.at(i).get_timestamp()) << tab << std::hex << static_cast<int>(+scifi_vec.at(i).get_status()) << tab << std::dec << static_cast<int>(scifi_vec.at(i).get_data1()) << '\n';
        }
		else{
            ss << std::dec << static_cast<int>(scifi_vec.at(i).get_timestamp()) << tab << std::hex << static_cast<int>(+scifi_vec.at(i).get_status()) << tab << std::dec << static_cast<int>(scifi_vec.at(i).get_data1()) << tab << std::dec << static_cast<int>(scifi_vec.at(i).get_data2()) << '\n';
        }
		std::cout << ss.str();
	}
}