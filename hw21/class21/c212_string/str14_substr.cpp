// str14_substr.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    std::cout << str.substr() << std::endl;
    std::cout << str.substr(7) << std::endl;
    std::cout << str.substr(8, 3) << std::endl;
}
