// io03_showpos.cpp

#include <iostream>

int main()
{
    int n = 1234;
    std::cout << "Default number display" << std::endl;
    std::cout << n << std::endl; // show positive
    std::cout << -n << std::endl;

    std::cout << "std::showpos for plus sign" << std::endl;
    std::cout << std::showpos << n << std::endl; // show positive
    std::cout << -n << std::endl;

    std::cout << "std::noshowpos" << std::endl;
    std::cout << std::noshowpos << n << std::endl; // show positive
    std::cout << -n << std::endl;
}
