// v05.cpp
#include <iostream>
#include <vector>

// reserve
int main()
{
    std::cout << "vector with 10 elements " << std::endl;
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Before reserve, v.size() = " << v.size()
              << ", v.capacity() = " << v.capacity() << std::endl;
    v.reserve(100);
    std::cout << "After reserve, v.size() = " << v.size()
              << ", v.capacity() = " << v.capacity() << std::endl;
}
