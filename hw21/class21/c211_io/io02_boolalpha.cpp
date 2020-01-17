// io02_boolalpha.cpp

#include <iostream>

int main()
{
    bool b = true;
    std::cout << "Default bool display" << std::endl;
    std::cout << b << std::endl;
    std::cout << !b << std::endl;

    std::cout << "std::boolalpha as true false" << std::endl;
    std::cout << std::boolalpha << b << std::endl;
    std::cout << !b << std::endl;

    std::cout << "std::noboolalpha" << std::endl;
    std::cout << std::noboolalpha << b << std::endl;
    std::cout << !b << std::endl;
}
