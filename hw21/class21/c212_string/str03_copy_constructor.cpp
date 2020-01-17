// str03_copy_constructor.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str1 = "CS 312 Winter 2020";
    // copy constructor
    std::string str2(str1);
    std::cout << str2 << std::endl;
}
