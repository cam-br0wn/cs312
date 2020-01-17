// io11_format7.cpp

#include <iostream>
#include <iomanip> // for setw()

int main()
{
    std::cout << std::fixed << std::setprecision(2)
              << "x =     " << std::setw(10) << std::right << 1.00 << std::endl;
    std::cout << "xx =    " << std::setw(10) << std::right << 10.00 << std::endl;
    std::cout << "xxx =   " << std::setw(10) << std::right << 100.00 << std::endl;
    std::cout << "xxxx =  " << std::setw(10) << std::right << 1000.00 << std::endl;
    std::cout << "xxxxx = " << std::setw(10) << std::right << 10000.00 << std::endl;
}
