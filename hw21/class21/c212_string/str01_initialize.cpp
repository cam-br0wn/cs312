// str01_initialize.cpp

#include <iostream>
#include <string>

int main()
{
    // the conventional way
    std::string str = "CS 312 Winter 2020";
    std::cout << "str:  " << str << std::endl;

    // initialize with {}
    std::string str1{"CS 312 Winter 2020"};
    std::cout << "str1: " << str1 << std::endl;

    // initialize with = {}
    std::string str2 = {"CS 312 Winter 2020"};
    std::cout << "str2: " << str2 << std::endl;

    // initailize with repeating char
    std::string str3(24, '=');
    std::cout << str3 << std::endl;
}
