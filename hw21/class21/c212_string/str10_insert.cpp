// str10_insert.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    // insert 16 dots starting at str[7]
    str.insert(7, 16, '.');
    str.insert(23, " ");
    str.insert(31, "Term ");
    std::cout << str << std::endl;
}
