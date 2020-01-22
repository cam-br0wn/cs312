// v20.cpp
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // method 1
    // print element cubed using a range for loop
    for (auto x : v)
        std::cout << x * x * x << " ";
    std::cout << std::endl;

    // method 2
    // using <cmath> pow()
    for (auto x : v)
        std::cout << std::pow(x, 3) << " ";
    std::cout << std::endl;
}
