// str08_chars_at.cpp

#include <iostream>
#include <string>
#include <stdexcept> // for string out of range error

int main()
{
    std::string str = "CS 312 Winter 2020";
    std::cout << "str.at(7) to str.at(12) = "
              << str.at(7)
              << str.at(8)
              << str.at(9)
              << str.at(10)
              << str.at(11)
              << str.at(12) << std::endl;
    // out of range is error
    std::cout << "str.at(60) = out of range error " << str.at(60) << std::endl;
}
