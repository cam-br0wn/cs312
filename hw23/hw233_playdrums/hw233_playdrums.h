/***************************************************************
hw233_playdrums.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw233
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/

// DO NOT MODIFY BELOW

#ifndef HW233_PLAYDRUMS_H_
#define HW233_PLAYDRUMS_H_

#ifndef HW222_CMIDIPACKET_H_
#include "hw222_CMidiPacket.h"
#endif

void create_gmdrums_vector(int start_note, int end_note);
void print_drums();

#endif // HW233_PLAYDRUMS_H_