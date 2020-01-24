/***************************************************************
hw234_main.cpp
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
using namespace CMP22;

int main()
{
	const int kFIRST_DRUM = 35;
	const int kLAST_DRUM = 81;
	create_scifisounds_vector(kFIRST_DRUM, kLAST_DRUM);
	print_scifi();
}