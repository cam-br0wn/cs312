
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