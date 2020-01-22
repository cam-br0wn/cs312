// v04.cpp
#include <iostream>
#include <vector>

// add ten elements using push_back inside a for loop
int main()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    std::cout << "v.size() = " << v.size() << std::endl;
    std::cout << "v.capacity() = " << v.capacity() << std::endl;
    for (const auto itr : v)
        std::cout << itr << "  ";
    std::cout << std::endl;
}
