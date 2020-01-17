// ss01_dec_hex_convert.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

// https : //stackoverflow.com/questions/20034297/decimal-to-hex-conversion-c-built-in-function/20034349
std::string dec2hex(const int dec)
{
	std::stringstream ss;
	ss << std::hex << dec; // int decimal_value
	std::string res(ss.str());

	return res;
}

// https : //stackoverflow.com/questions/20034297/decimal-to-hex-conversion-c-built-in-function/20034349
std::string hex2dec(const int hex)
{
	int dec;
	std::stringstream ss;
	ss << hex;						 // std::string hex_value
	ss >> std::hex >> dec; //int decimal_value
	return ss.str();
}

int main()
{
	std::cout << "== Number base conversion\n";
	std::cout << "dec2hex(2020) 0x" << dec2hex(2020) << std::endl;
	std::cout << "hex2dec(0x734) " << hex2dec(0x7e4) << std::endl;
}
