// v28.cpp
#include <iostream>
#include <vector>

// duplicate elements of a vector
int main()
{
    const std::vector<int> v = {0, 1, 2, 3, 4};
    std::vector<int> outvec;
    for (auto ix = 0; ix < 7; ++ix)
    {
        std::copy(v.begin(), v.end(), back_inserter(outvec));
    }
    for (auto itr : outvec)
        std::cout << itr << " ";
    std::cout << std::endl;
}