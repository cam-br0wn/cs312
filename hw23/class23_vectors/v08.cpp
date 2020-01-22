// v08.cpp
#include <iostream>
#include <vector>

// Accessing individual elements of a vector
// There are two methods available to access a single vector element.
//     brackets
//     the at( ) member function.
// The difference is that at() is range checked and will throw an error
// if you try to access a position that is outside of the vector's size.
// accessing a single element using [ ]
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "v[4] = " << v[4] << std::endl;
}
