// v15.cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Method 1
    int count = 0;
    for (auto i : v)
    {
        if ((count > 4) && (count < 8))
            std::cout << i << " ";
        ++count;
    }
    std::cout << std::endl;

    // Method 2
    for (auto i : {5, 6, 7})
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
