// v17.cpp
#include <iostream>
#include <vector>

// print elements using an alternate begin() end() syntax
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for ( auto itr = begin( v ); itr != end( v ); ++itr )
        std::cout << *itr << " ";
    std::cout << std::endl;
}
