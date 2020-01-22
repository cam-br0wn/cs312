// v10.cpp
#include <iostream>
#include <vector>

// accessing a single element using .at()
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "v.at(4) = " << v.at( 4 ) << std::endl;
}
