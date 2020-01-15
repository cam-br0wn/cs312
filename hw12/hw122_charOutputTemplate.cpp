/***************************************************************
hw122_charOutputTemplate.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw122
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

#include <iostream>
#include <string>
#include <bitset>
#include <typeinfo>

template <typename T>
void print(T x, std::string msg) {

      int i = static_cast<int>(x);
      std::cout << msg << std::dec << std::showbase << i << std::endl;
      std::cout << msg << std::hex << std::noshowbase << i << std::endl;
      std::cout << msg << std::hex << std::showbase << i << std::endl;
      std::cout << msg << std::bitset<8>(x) <<  std::endl;

      std::cout << " \n" << std::endl;
 }


int main() {
  int c = 9;
  signed char sc = 50;
  unsigned char uc = 144;

  print(c, "c: = ");
  print(sc, "sc: = ");
  print(uc, "uc: = ");
}

/* Question: Why did this happen? 
    We needed to cast the type of the variable (<char>) to an <int> type variable to ouput them correctly. 
 */
