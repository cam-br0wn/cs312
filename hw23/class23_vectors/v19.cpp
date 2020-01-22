// v19.cpp
#include <iostream>
#include <vector>

// print the odd numbered indices
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto n : {1, 3, 5, 7, 9})
        std::cout << v[n] << " ";
    std::cout << std::endl;

    // method 2
    int count{0};
    for (auto itr : v)
    {
        if (count % 2 == 1)
            std::cout << itr << " ";
        ++count;
    }
    std::cout << std::endl;
}
