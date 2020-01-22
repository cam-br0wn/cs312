// v03.cpp
#include <iostream>
#include <vector>

// add one element with push_back

int main()
{
    std::cout << "vector starts with 5 elements" << std::endl;
    std::vector<int> v = {0, 2, 4, 6, 8};
    for (const auto itr : v)
        std::cout << itr << "  ";
    std::cout << "\nv.size() = " << v.size() << std::endl;
    std::cout << "v.capacity() = " << v.capacity() << std::endl;
    std::cout << "add one more element " << std::endl;
    v.push_back(10);
    for (const auto itr : v)
        std::cout << itr << "  ";
    std::cout << "\nv.size() = " << v.size() << std::endl;
    std::cout << "v.capacity() = " << v.capacity() << std::endl;
    std::cout << std::endl;
}
