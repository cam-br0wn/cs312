// str12_replace.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    // replace 1 char at str[10]
    str.replace(10, 1, "n");
    std::cout << str << std::endl;

    // replace 3 chars starting at str[8]
    str.replace(8, 3, "ond");
    std::cout << str << std::endl;
}
