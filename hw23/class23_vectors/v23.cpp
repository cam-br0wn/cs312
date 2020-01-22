// v23.cpp
#include <iostream>
#include <vector>

int main()
{
    // print vector backwards
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
}
