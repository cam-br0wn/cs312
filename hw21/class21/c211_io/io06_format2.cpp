// io06_format2.cpp

#include <iostream>

int main()
{
    std::cout << "formatting default\n";
    std::cout << "x =     " << 1 << std::endl;
    std::cout << "xx =    " << 10 << std::endl;
    std::cout << "xxx =   " << 100 << std::endl;
    std::cout << "xxxx =  " << 1000 << std::endl;
    std::cout << "xxxxx = " << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "formatting lining up quotes\n";
    std::cout << "    x = " << 1 << std::endl;
    std::cout << "   xx = " << 10 << std::endl;
    std::cout << "  xxx = " << 100 << std::endl;
    std::cout << " xxxx = " << 1000 << std::endl;
    std::cout << "xxxxx = " << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "formatting using tab char \t\n";
    std::cout << "x =\t" << 1 << std::endl;
    std::cout << "xx =\t" << 10 << std::endl;
    std::cout << "xxx =\t" << 100 << std::endl;
    std::cout << "xxxx =\t" << 1000 << std::endl;
    std::cout << "xxxxx =\t" << 10000 << std::endl;
    std::cout << std::endl;

    std::cout << "formatting using spaces to offset " 
              << "the length of the number\n";
    std::cout << "x =         " << 1 << std::endl;
    std::cout << "xx =       " << 10 << std::endl;
    std::cout << "xxx =     " << 100 << std::endl;
    std::cout << "xxxx =   " << 1000 << std::endl;
    std::cout << "xxxxx = " << 10000 << std::endl;
}
