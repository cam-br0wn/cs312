// v26.cpp
#include <iostream>
#include <vector>

// erase resize
int main()
{
    // from v25.cpp
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for ( const auto itr : v )
        std::cout << itr << " ";
    v.erase( v.begin() + 2, v.begin() + 5 );
    std::cout << "\nafter erase [2:5)" << std::endl;
    for ( const auto itr : v )
        std::cout << itr << " ";
    std::cout << "\nv.size() = " << v.size() << std::endl;

    v.resize( 10 );
    std::cout << "after resize" << std::endl;
    for ( const auto itr : v )
        std::cout << itr << " ";
    std::cout << "\nv.size() = " << v.size() << std::endl;
}
