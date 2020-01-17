// io01_global_struct.cpp

#include <iostream>
#include <string>

struct MyGlobals
{
    bool b = true;
    char c = '#'; // single char, single quotes
    int n = 1234;
    float f = 5.67891;
    std::string s = "CS 312"; // string, double quotes

    void print();
};

void MyGlobals::print()
{
    std::cout << "g.b = " << b << std::endl;
    std::cout << "g.c = " << c << std::endl;
    std::cout << "g.n = " << n << std::endl;
    std::cout << "g.f = " << f << std::endl;
    std::cout << "g.s = " << s << std::endl;
}

int main()
{
    MyGlobals g;
    g.print();
    return 0;
}
