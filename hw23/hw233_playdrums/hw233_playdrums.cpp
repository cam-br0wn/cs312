// boilerplate here

#ifndef HW233_PLAYDRUMS_H_
#include "hw233_playdrums.h"
#endif

#include <iostream>
#include <vector>

using namespace CMP22;

std::vector<CMidiPacket> drum_vec;

void create_gmdrums_vector(int start_note, int end_note)
{
#ifdef USE_THESE_CONSTS
	const int kNON_DELTA_TIME = 500; // time between NON's
	const int kNON_DURATION = 100;	 // time NOF appears after NON
#endif
	std::cout << "create_gmdrums_vector(...) needs to be implemented.\n";
}

void print_drums()
{
	std::cout << "print_drums() needs to be implemented.\n";
}