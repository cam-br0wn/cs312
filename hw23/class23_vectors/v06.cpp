// v06.cpp
#include <iostream>
#include <vector>

// empty
// The empty() function returns true if the vector holds at least one element.
// It returns false if the vector holds zero elements.
// It does not remove elements from the vector.
int main()
{
    std::cout << "vector with 10 elements " << std::endl;
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << std::boolalpha << "v.empty  = " << v.empty() << std::endl;
}
