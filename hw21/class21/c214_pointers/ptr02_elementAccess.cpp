// ptr02_elementAccess.cpp

#include <iostream>

class CMyClass
{
public:
    int x;
    CMyClass();
};

CMyClass::CMyClass() : x{100}
{
}

int main()
{
    // allocate on stack
    CMyClass mc;
    // allocate on heap
    CMyClass *pmc = new CMyClass();
    std::cout << mc.x << std::endl;
    std::cout << pmc->x << std::endl;
    std::cout << (*pmc).x << std::endl;
}