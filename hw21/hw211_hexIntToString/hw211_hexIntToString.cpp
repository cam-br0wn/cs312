/***************************************************************
hw211_hexIntToString.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw211
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-18
TIME: 13:13:46
****************************************************************/
#include <stdio.h>
#include <iostream>
#include <sstream>

int main()
{
    int n = 0x90;

    std::ostringstream oss;
    oss << std::hex << n;
    std::cout << oss.str() << std::endl;

    // oss.flush()
    oss.str("");

    oss << std::hex << std::showbase << n;
    std::cout << oss.str() << std::endl;
}

/* What is the purpose of the extra curly braces in the original example? 

   The extra curly braces creates an <ostringstream> struct within the scope of those braces. So, each 'oss' in
   the different set of braces references different <ostringstream> structs. 

   That is why we get an error for declaring the same reference when those curly braces aren't included. To get around
   this issue, we just "flushed" out the contents of the 'oss' so we can reassign its string contents. 
*/ 