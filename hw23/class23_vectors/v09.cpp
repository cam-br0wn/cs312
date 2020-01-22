// v09.cpp
#include <iostream>
#include <vector>

// accessing an out of range element using [ ]

//no range checking performed//
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "v[11] = " << v[ 11 ] << std::endl;
}
