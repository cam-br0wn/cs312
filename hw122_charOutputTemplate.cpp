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


#define ISUNSIGNED(a) (a >= 0 && ~a >= 0) 

template <typename T>
void print(T x, std::string msg) {

    //  std::cout << ISUNSIGNED(x); <<std::endl;

      std::cout << std::dec << std::showbase << x << std::endl;
      std::cout << std::hex << std::noshowbase << x << std::endl;
      std::cout << std::hex << std::showbase << x << std::endl;
      std::cout << std::bitset<8>(x) <<  std::endl;
 }


int main() {
  int c = 9;
  signed char sc = 250;
  unsigned char uc = 144;

  print(c, "c: = ");
  print(sc, "sc: = ");
  print(uc, "uc: = ");
}

/* Question: Why did this happen? 
    We needed to cast the type of the variable (<char>) to an <int> type variable to ouput them correctly. 
 */