// ptr04_doubleDelete.cpp

#include <iostream>
#include <string>

int main()
{
    int *p = new int; // assign pointer p on the heap to point to an int somewhere
    *p = 1234;        // the address on the heap pointed to by p now holds 1234

    int *q = new int; // assign pointer p on the heap to point to an int somewhere
    *q = 5678;        // the address on the heap pointed to by p now holds 4321

    // double deleting a pointer

    std::cout << "Before p = q" << std::endl;
    std::cout << "\taddress p = " << p << "\tvalue p = " << *p << std::endl;
    std::cout << "\taddress q = " << q << "\tvalue q = " << *q << std::endl;

    p = q;
    std::cout << "After p = q" << std::endl;
    std::cout << "\taddress p = " << p << "\tvalue p = " << *p << std::endl;
    std::cout << "\taddress q = " << q << "\tvalue q = " << *q << std::endl;

    std::cout << "delete p" << std::endl;
    delete p;
    std::cout << "Next delete q" << std::endl;
    std::cout << "BAD IDEA: double delete error" << std::endl;
    delete q;
}
