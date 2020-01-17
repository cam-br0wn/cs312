// str11_erase.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    // erase 7 chars starting at str[7]
    str.erase(7, 7);
    std::cout << str << std::endl;
}
