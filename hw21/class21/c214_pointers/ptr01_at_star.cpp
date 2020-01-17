// ptr01_at_star.cpp

#include <iostream>
#include <string>

#include <iostream>
#include <string>

int main()
{
    std::cout << "---------------------------\n";
    std::cout << "int n = 1234 and int *p = &n\n";
    // assign a variable of type int
    int n = 1234;
    // p is a pointer to a memory address
    int *p;
    // &n is the address of n is
    p = &n;
    // p = &n
    std::cout << "n       = " << n
              << "\np     = " << p
              << "\n&n    = " << &n
              << "\n*(&n) = " << *(&n)
              << "\n*p    = " << *p
              << std::endl;

    std::cout << "---------------------------\n";
    std::cout << "int *q = new int and *q = 4321\n";
    int *q = new int;
    *q = 4321;
    std::cout << "q     = " << q
              << "\n&(*q) = " << &(*q)
              << "\n*q    = " << *q << std::endl;

    std::cout << "---------------------------\n";
    std::cout << "int *r = new int(5678)\n";
    int *r = new int(5678);
    std::cout << "r memory address = " << r << std::endl;
    r = q;
    std::cout << "r = q, r memory address = " << r << std::endl;
    std::cout << "r     = " << r
              << "\nq     = " << q
              << "\n&(*r) = " << &(*r)
              << "\n&(*q) = " << &(*q)
              << "\n*r    = " << *r
              << "\n*q    = " << *q
              << std::endl;

    std::cout << "---------------------------\n";
    std::cout << "delete q and set q = nullptr";
    delete q;
    q = nullptr;
    std::cout << "\nq  = " << q
              << "\nr  = " << r
              << "\n*r = " << *r << std::endl;

    std::cout << "---------------------------\n";
    std::cout << "original memory address of r has disappeared\n";
    std::cout << "memory holding 5678 has been leaked\n";
    std::cout << "5678 is still in memory but r no longer points to it\n";
}
