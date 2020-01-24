/***************************************************************
hw232_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw232
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-22
TIME: 14:40:17
****************************************************************/

#include <iostream>
// add more includes as needed

void print_header()
{
  std::cout << "======================================================\n";
  std::cout << "General MIDI drum kit note assignments on channel 10\n";
  std::cout << "Use status 0x99 for NON\n";
  std::cout << "Use status 0x99 and velocity of 0 for NOF\n";
  std::cout << "======================================================\n";
}

int main() {
  print_header();
  for (auto itr : kVEC_DRUM_NAMES)
    std::cout << itr << std::endl;
}
