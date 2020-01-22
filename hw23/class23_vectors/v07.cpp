// v07.cpp
#include <iostream>
#include <vector>

// clear
//    The clear() function is used to remove all elements from a vector.
int main()
{
    std::cout << "vector with 10 elements " << std::endl;
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto itr : v)
        std::cout << itr << "  ";
    std::cout << std::endl;

    std::cout << "v.size() = " << v.size() << std::endl;
    std::cout << "v.capacity() = " << v.capacity() << std::endl;
    v.clear();
    std::cout << std::boolalpha << "after v.clear(), v.empty() = " << v.empty() << std::endl;
    std::cout << "v.size() = " << v.size() << std::endl;
    std::cout << "v.capacity() = " << v.capacity() << std::endl;
}
