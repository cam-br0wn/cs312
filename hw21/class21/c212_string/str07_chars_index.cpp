// str07_chars_index.cpp

#include <iostream>
#include <string>
#include <stdexcept> // for string out of range error

int main()
{
    std::string str = "CS 312 Winter 2020";
    std::cout << "str[7] to str[12] = "
              << str[7]
              << str[8]
              << str[9]
              << str[10]
              << str[11]
              << str[12] << std::endl;
    // out of range is undefined
    std::cout << "str[60] = out of range undefined " << str[60] << std::endl;
}
