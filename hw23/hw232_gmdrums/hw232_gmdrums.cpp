/***************************************************************
hw232_gmdrums.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw232
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-22
TIME: 14:40:17
****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>

const std::vector<std::string> kDRUM_NAMES_VEC = {
		"35 Bass Drum 2",
		"36 Bass Drum 1",
		"37 Side Stick",
		"38 Snare Drum 1",
		"39 Hand Clap",
		"40 Snare Drum 2",
		"41 Low Tom 2",
		"42 Closed Hi-hat",
		"43 Low Tom 1",
		"44 Pedal Hi-hat",
		"45 Mid Tom 2",
		"46 Open Hi-hat",
		"47 Mid Tom 1",
		"48 High Tom 2",
		"49 Crash Cymbal 1",
		"50 High Tom 1",
		"51 Ride Cymbal 1",
		"52 Chinese Cymbal",
		"53 Ride Bell",
		"54 Tambourine",
		"55 Splash Cymbal",
		"56 Cowbell",
		"57 Crash Cymbal 2",
		"58 Vibra Slap",
		"59 Ride Cymbal 2",
		"60 High Bongo",
		"61 Low Bongo",
		"62 Mute High Conga",
		"63 Open High Conga",
		"64 Low Conga",
		"65 High Timbale",
		"66 Low Timbale",
		"67 High Agogo",
		"68 Low Agogo",
		"69 Cabasa",
		"70 Maracas",
		"71 Short Whistle",
		"72 Long Whistle",
		"73 Short Guiro",
		"74 Long Guiro",
		"75 Claves",
		"76 High Wood Block",
		"77 Low Wood Block",
		"78 Mute Cuica",
		"79 Open Cuica",
		"80 Mute Triangle",
		"81 Open Triangle"};

void print_header()
{
	std::cout << "======================================================\n";
	std::cout << "General MIDI drum kit note assignments on channel 10\n";
	std::cout << "	Use status 0x99 for NON \n";
	std::cout << "	Use status 0x99 and velocity of 0 for NOF \n";
	std::cout << "======================================================\n \n";
}

int main()
{
	print_header();
	for (auto itr : kDRUM_NAMES_VEC)
		std::cout << itr << std::endl;

	return 0;
}