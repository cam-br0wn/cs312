// io09_format5.cpp

#include <iostream>
#include <iomanip> // for setw()

int main()
{
    std::cout << "x = "
              << "<" << std::setw(10) << 1 << ">" << std::endl;
    std::cout << "<" << std::setw(10) << "xx = " << 10 << ">" << std::endl;
    std::cout << "xxx = "
              << "<" << std::setw(10) << 100 << ">" << std::endl;
    std::cout << "xxxx = " << 1000 << "<" << std::setw(10) << ">" << std::endl;
    std::cout << "xxxxx = "
              << "<" << std::setw(10) << 10000 << ">" << std::endl;
}
