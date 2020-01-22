// rand7.cpp
#include <iostream>
#include <random>
#include <vector>

// with no seed, this code produces the same series every time it is run
int main()
{
    const std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> vout;
    // make 7 copies of v.
    for (auto ix = 0; ix < 7; ++ix)
        std::copy(v.begin(), v.end(), back_inserter(vout));
    std::cout << "before shuffle\n";
    for (auto itr : vout)
        std::cout << itr << " ";
    std::cout << std::endl;

    std::shuffle(vout.begin(), vout.end(), std::default_random_engine(0));
    std::cout << "after shuffle\n";
    for (auto itr : vout)
        std::cout << itr << " ";
    std::cout << std::endl;
}
