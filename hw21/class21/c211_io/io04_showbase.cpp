// io04_showbase.cpp

#include <iostream>

int main()
{
    // default displays numbers in decimal
    int n = 0xFEEDFACE;
    std::cout << n << std::endl;

    // std::hex displays the number in hexadecimal format without the 0x prefix
    std::cout << std::hex << n << std::endl;

    // std::showbase adds the 0x prefix to hexadecimal numbers.
    n = 0xDEADBEEF;
    std::cout << std::hex << std::showbase << n << std::endl;

    n = 0xBADF00D;
    // std::noshowbase removes the 0x prefix from a previous call
    std::cout << std::hex << std::noshowbase << n << std::endl;

    // std::dec reverts back to decimal after a previous call to std::hex
    std::cout << std::dec << n << std::endl;
}
