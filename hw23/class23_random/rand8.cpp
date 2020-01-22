// rand8.cpp
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

//     - with seed ::
//                    this code produces a different series every time
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

    // obtain a time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(outvec.begin(), outvec.end(), std::default_random_engine(seed));

    std::cout << "after shuffle\n";
    for (auto itr : outvec)
        std::cout << itr << " ";
    std::cout << std::endl;
}
