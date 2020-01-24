/***************************************************************
hw233_playdrums.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw233
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:45:40
****************************************************************/

#ifndef HW233_PLAYDRUMS_H_
#include "hw233_playdrums.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace CMP22;

std::vector<CMidiPacket> drum_vec;

void create_gmdrums_vector(int start_note, int end_note)
{

	const int kNON_DELTA_TIME = 500; // time between NON's
	const int kNON_DURATION = 100;	 // time NOF appears after NON

	for(int i = 35; i < 82; i++){
		
		int timestamp_NON = (i - 35) * kNON_DELTA_TIME;
		int timestamp_NOF = timestamp_NON + kNON_DURATION;
		uint8_t status_NON = 0x99;
		uint8_t status_NOF = 0x89;
		int data1 = i;
		int data2_NON = 100;
		int data2_NOF = 0;
		CMidiPacket mp_NON(timestamp_NON, status_NON, data1, data2_NON);
		CMidiPacket mp_NOF(timestamp_NOF, status_NOF, data1, data2_NOF);
		drum_vec.push_back(mp_NON);
		drum_vec.push_back(mp_NOF);
	}
}

void print_drums()
{
	for(int i = 0; i < drum_vec.size(); i++){
		std::stringstream ss;
		std::string res;
		std::string tab = "\t";
		ss << std::dec << static_cast<int>(drum_vec.at(i).get_timestamp()) << tab << std::hex << static_cast<int>(+drum_vec.at(i).get_status()) << tab << std::dec << static_cast<int>(drum_vec.at(i).get_data1()) << tab << std::dec << static_cast<int>(drum_vec.at(i).get_data2()) << '\n';
		std::cout << ss.str();
	}
}