// ss06_binary_bitset.cpp

#include <iostream>
#include <string>

int main()
{
    std::bitset<8> bitset_0xAA(0xaa);
    std::bitset<8> bitset_0x55(0x55);
    std::bitset<16> bitset_0xAA55(0xaa55);
    std::bitset<32> bitset32_0xAA55(0xaa55);

    std::cout << "bitset8_0xAA = " << bitset_0xAA << std::endl;
    std::cout << "bitset8_0x55 = " << bitset_0x55 << std::endl;
    std::cout << "bitset16_0xAA55 = " << bitset_0xAA55 << std::endl;
    std::cout << "bitset32_0xAA55 = " << bitset32_0xAA55 << std::endl;

    std::bitset<24> b24("111100001111000011110000");
    std::cout << "b24(\" 111100001111000011110000\") = " << b24 << std::endl;
}
