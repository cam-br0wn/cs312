// v25.cpp
#include <iostream>
#include <vector>

// erase a range of elements
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for ( const auto itr : v )
        std::cout << itr << " ";
    std::cout << std::endl;
    v.erase( v.begin() + 2, v.begin() + 5 );
    for ( const auto itr : v )
        std::cout << itr << " ";
    std::cout << "\nafter erase [2:5) v.size() = " << v.size() << std::endl;
}
