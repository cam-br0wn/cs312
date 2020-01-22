// rand9.cpp
#include <iostream>
#include <random>
#include <vector>

//     - using std::random_device and std::default_random_engine ::
//          this code produces a different series every time
int main()
{

    const std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> outvec;
    for (auto ix = 0; ix < 7; ++ix)
        std::copy(v.begin(), v.end(), back_inserter(outvec));

    std::cout << "before shuffle\n";
    for (auto itr : outvec)
        std::cout << itr << " ";
    std::cout << std::endl;

    // use std::random_device for seed
    std::random_device rd;
    std::default_random_engine dre(rd());
    std::shuffle(outvec.begin(), outvec.end(), dre);

    std::cout << "after shuffle\n";
    for (auto itr : outvec)
        std::cout << itr << " ";
    std::cout << std::endl;
}
