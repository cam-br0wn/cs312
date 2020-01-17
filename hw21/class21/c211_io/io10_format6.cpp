// io10_format6.cpp

#include <iostream>
#include <iomanip> // for setinternal
int main()
{
   // std::right adjusts the length of the strings to the left of 
   // std::setw(10) to 10 total characters by prepending spaces to the beginning of the string. 
   // I did not find a way to get the first line formatted correctly.

    std::cout << "std::right -> std::setw(10) -> x = \n";
    std::cout << std::right << std::setw(10) << "x = " << 1 << std::endl;
    std::cout << std::right << std::setw(10) << "xx = " << 10 << std::endl;
    std::cout << std::right << std::setw(10) << "xxx = " << 100 << std::endl;
    std::cout << std::right << std::setw(10) << "xxxx = " << 1000 << std::endl;
    std::cout << std::right << std::setw(10) << "xxxxx = " << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "x = -> std::right -> std::setw(10)\n";
    std::cout << "x = " << std::right << std::setw(10) << 1 << std::endl;
    std::cout << "xx = " << std::right << std::setw(10) << 10 << std::endl;
    std::cout << "xxx = " << std::right << std::setw(10) << 100 << std::endl;
    std::cout << "xxxx = " << std::right << std::setw(10) << 1000 << std::endl;
    std::cout << "xxxxx = " << std::right << std::setw(10) << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "x = -> std::right -> std::setw(10--)\n";
    std::cout << "x  " << std::right << std::setw(10) << "= " << 1 << std::endl;
    std::cout << "xx  " << std::right << std::setw(9) << "= " << 10 << std::endl;
    std::cout << "xxx  " << std::right << std::setw(8) << "= " << 100 << std::endl;
    std::cout << "xxxx  " << std::right << std::setw(7) << "= " << 1000 << std::endl;
    std::cout << "xxxxx  " << std::right << std::setw(6) << "= " << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "x = -> std::right -> = std::setw(10--) -> number\n";
    std::cout << "x  " << std::right << "= " << std::setw(10) << 1 << std::endl;
    std::cout << "xx  " << std::right << "= " << std::setw(9)  << 10 << std::endl;
    std::cout << "xxx  " << std::right << "= "  << std::setw(8) << 100 << std::endl;
    std::cout << "xxxx  " << std::right << "= " << std::setw(7) << 1000 << std::endl;
    std::cout << "xxxxx  " << std::right << "= " << std::setw(6) << 10000 << std::endl;
    std::cout << std::endl;
}
