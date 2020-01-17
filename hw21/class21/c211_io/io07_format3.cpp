// io07_format3.cpp

#include <iostream>
#include <iomanip> // for setw()

int main()
{
    // std::setw() adjusts the length of the strings to the left of std::setw(10)
    // to 10 total characters by appending spaces to the end of the string.
    std::cout << "x = " << std::setw(10) << 1 << std::endl;
    std::cout << "xx = " << std::setw(10) << 10 << std::endl;
    std::cout << "xxx = " << std::setw(10) << 100 << std::endl;
    std::cout << "xxxx = " << std::setw(10) << 1000 << std::endl;
    std::cout << "xxxxx = " << std::setw(10) << 10000 << std::endl;
}
