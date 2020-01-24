/***************************************************************
hw231_testCMP22.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw231
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-22
TIME: 13:38:44
****************************************************************/
#include "hw222_CMidiPacket.h"

using namespace CMP22;

int main(int argc, char const *argv[])
{
	CMidiPacket mp(1000, 0x90, 60, 100);
	mp.print();
}