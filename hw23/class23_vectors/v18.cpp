// v18.cpp
#include <iostream>
#include <vector>

// print even numbered indices
int main()
{
    // method 1
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for ( auto n : {0, 2, 4, 6, 8} )
        std::cout << v[ n ] << " ";
    std::cout << std::endl;

    // method 2
    int k{0};
    for ( int i = 0; i < v.size(); ++i )
    {
        if ( i % 2 == 0 )
            std::cout << v[ i ] << " ";
    }
    std::cout << std::endl;
}
