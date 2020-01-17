// ptr03_set2null.cpp

#include <iostream>
#include <string>

int main()
{
    int *p = new int; // assign pointer p on the heap to point to an int somewhere
    *p = 1234;        // the address on the heap pointed to by p now holds 1234

    int *q = new int; // assign pointer p on the heap to point to an int somewhere
    *q = 5678;        // the address on the heap pointed to by p now holds 4321

    p = q;
    delete p;
    int *r = new int;
    *r = 9876;
    std::cout << "-------------------------------\n";
    std::cout << "p deleted but value still there " << p << std::endl;
    std::cout << "DANGER: it might have been overwritten with another value\n";
    std::cout << "*p = " << *p << std::endl;
    std::cout << "You can spend hours or days tracking down this kind of bug.\n";
    std::cout << "MORAL: Always set a pointer to nullptr after deleting it.\n";

    std::cout << "-------------------------------\n";
    std::cout << "After p = nullptr you'll get a Runtime Error if you try to access *p again\n";
    std::cout << "At least you have a chance to fix it before the client sees it.\n";
    p = nullptr;
    std::cout << "*p = " << *p << std::endl;
}
