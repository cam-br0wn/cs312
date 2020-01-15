/***************************************************************
hw123_charLoop.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw123
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

/* JE =================================
GRADE:	97
COMMENTS: Insufficient explanation

My for loop
for (char c = 0; c <= 127; ++c)
acutally loops 128 times
on loop 127 when c = 128 = -128 as signed char
from there ++c goes from -128 back to 0
and then starts over again
You could fix it several ways
==
  for (unsigned char c = 0; c <= 127; ++c)
    std::cout << static_cast<int>(c) << " = " << c << std::endl;
==
  for (char c = 0; c < 127; ++c)
    std::cout << static_cast<int>(c) << " = " << c << std::endl;

char cc = 127;    
std::cout << static_cast<int>(127) << " = " << cc << std::endl;
==
  for (int c = 0; c <= 127; ++c)
    std::cout << c << " = "<< static_cast<char>(c) << std::endl;
==
  for (int16_t c = 0; c <= 127; ++c)
    std::cout << c << " = "<< static_cast<char>(c) << std::endl;
======================================*/

#include <iostream>

int main()
{
  for (int c = 0; c <= 127; ++c)
    std::cout << static_cast<int>(c) << " = " << static_cast<char>(c) << std::endl;
}

/* Question: Question: What caused the infinite loop? 
    There was an infinite loop as 'c' was declared as type 'char' in the for-loop. In the given source code,
    when it iterates (c++), 'c' wasn't being incremented properly as it was adding 1 to a char type. This caused the 
    program to run infinitely. 
 */
