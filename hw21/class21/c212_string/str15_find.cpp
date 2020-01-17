// str15_find.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    std::size_t ix = str.find("Win");
    std::cout << "Win found at position " << ix << std::endl;
    ix = str.find("2017");
    std::cout << "\n2017 found at position "
              << std::hex << std::showbase << ix << std::endl;
    std::cout << "std::string::npos == "
              << std::showbase << std::hex << std::string::npos
              << " means Not Found" << std::endl;
}
