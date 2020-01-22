// v02.cpp
#include <iostream>
#include <vector>

// size and capacity
// The size of a vector is the actual number of elements in the vector.
// Capacity is total number of elements the vector could hold before more memory
// needs to be allocated.
int main()
{
    std::vector<int> v = {0, 2, 4, 6, 8};
    std::cout << "v.size(): " << v.size() << std::endl;
    std::cout << "v.capacity(): " << v.capacity() << std::endl;
}
