// io12_format8.cpp

#include <iostream>
#include <iomanip> // for setw()
#include <string>

int main()
{
    // Uses std::setfill(char) as the padding instead of the default space character.
    const char kFILL = '.';
    std::cout << "x" << std::setfill(kFILL) << std::setw(25) << 1 << std::endl;
    std::cout << "xx" << std::setfill(kFILL) << std::setw(25) << 10 << std::endl;
    std::cout << "xxx" << std::setfill(kFILL) << std::setw(25) << 100 << std::endl;
    std::cout << "xxxx" << std::setfill(kFILL) << std::setw(25) << 1000 << std::endl;
    std::cout << "xxxxx" << std::setfill(kFILL) << std::setw(25) << 10000 << std::endl;
}
