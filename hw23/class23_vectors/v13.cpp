// v13.cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for ( auto itr : v )
        std::cout << itr << " ";
    std::cout << std::endl;
}
