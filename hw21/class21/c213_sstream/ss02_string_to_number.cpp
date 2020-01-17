// ss02_string_to_number.cpp

#include <iostream>
#include <string>
#include <sstream>

int str2num(const std::string &s, bool is_dec = true)
{
	int x;
	if (is_dec)
		x = std::stoi(s);
	else
	{
		std::size_t found = s.find("0x");
		if (found != std::string::npos) // 0x was found
		{
			std::string s1 = s.substr(2);
			x = std::stoi(s1, 0, 16);
		}
		else // 0x not found
			x = std::stoi(s, 0, 16);
	}
	return x;
}

int main()
{
	const bool hex = false;
	std::cout << "== String to number conversion\n";
	std::cout << "str2num(\"2020\")  = " << str2num("2020") << std::endl;
	std::cout << "str2num(\"7e4\", hex)  = " << str2num("7e4", hex) << std::endl;
	std::cout << "str2num(\"0x7e4\", hex) = " << str2num("0x7e4", hex) << std::endl;
}
