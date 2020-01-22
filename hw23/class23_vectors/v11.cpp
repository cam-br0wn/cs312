// v11.cpp
#include <iostream>
#include <vector>

// accessing an out of range element using .at()
//range errors caught at compile time//
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // The error is caught by the compiler, not by the user.
    std::cout << "v.at(11) = " << v.at( 10 ) << std::endl;
}
