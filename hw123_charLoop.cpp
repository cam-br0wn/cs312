/***************************************************************
hw123_charLoop.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw123
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

#include <iostream>

int main() {
  for (int c = 0; c <= 127; ++c)
    std::cout << static_cast<int>(c) << " = " << static_cast<char>(c) << std::endl;
}


/* Question: Question: What caused the infinite loop? 
    There was an infinite loop as 'c' was declared as type 'char' in the for-loop. In the given source code,
    when it iterates (c++), 'c' wasn't being incremented properly as it was adding 1 to a char type. This caused the 
    program to run infinitely. 
 */
