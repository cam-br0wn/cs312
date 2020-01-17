// str09_assign.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str;
    // create a string of 36 = characters
    str.assign(36, '=');
    std::cout << str << std::endl;
    str.assign("line1\n\tline2\n\t\tline3");
    std::cout << str << std::endl;
    str.assign(36, '=');
    std::cout << str << std::endl;
}
