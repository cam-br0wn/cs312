// io08_format4.cpp

#include <iostream>
#include <iomanip> // for setw()

int main()
{
    // placement of setw(10) makes a difference ::
    std::cout << std::setw(10) << "x = " << 1 << std::endl;
    std::cout << std::setw(10) << "xx = " << 10 << std::endl;
    std::cout << std::setw(10) << "xxx = " << 100 << std::endl;
    std::cout << std::setw(10) << "xxxx = " << 1000 << std::endl;
    std::cout << std::setw(10) << "xxxxx = " << 10000 << std::endl;
}
