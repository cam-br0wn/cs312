/***************************************************************
hw121_charOutput.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw121
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

#include <iostream>

int main() {
  // MIDI message
  unsigned char status = 144;
  char data1 = 60;
  char data2 = 100;

  std::cout << "status: = " << static_cast<unsigned>(status)<< std::endl;
  std::cout << "data1: = " << static_cast<int>(data1) << std::endl;
  std::cout << "data2: = " << static_cast<int>(data2) << std::endl;
}

/* Question: Why did this happen? 
    We needed to cast the type of the variable (<char>) to an (<int>) type variable to ouput them correctly. 
 */