// ss03_stringstreams.cpp

#include <iostream>
#include <string>
#include <sstream>

void sstream_convert(int n, std::string &decStr, std::string &hexStr)
{
    std::istringstream iss(std::to_string(n));
    iss >> n;
    decStr = iss.str();

    std::ostringstream oss;
    oss << std::hex << n;
    hexStr = oss.str();
}

int main()
{
    int i = 144;
    int h = 0x90;

    std::cout << "\nUsing std::to_string()\n=====================\n";
    std::cout << "std::to_string(144) = " << std::to_string(i) << std::endl;
    std::cout << "std::to_string(0x90) = " << std::to_string(h) << std::endl;

    std::string decStr{""};
    std::string hexStr{""};
    sstream_convert(i, decStr, hexStr);
    std::cout << "\nUsing std::sstream and pass by reference\n=====================\n";
    std::cout << decStr << "\n"
              << hexStr << std::endl;
}
