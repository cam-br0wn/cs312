// v16.cpp
#include <iostream>
#include <vector>

// print elements using an iterator for loop
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for ( auto itr = v.begin(); itr != v.end(); ++itr )
        std::cout << *itr << " ";
    std::cout << std::endl;
}
