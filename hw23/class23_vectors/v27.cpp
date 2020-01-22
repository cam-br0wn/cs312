// v27.cpp
#include <iostream>
#include <vector>

// insert
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto itr : v)
        std::cout << itr << " ";
    std::cout << std::endl;
    std::cout << "v.size = " << v.size() << std::endl;
    for (int count = 5; count < 10; ++count)
    {
        v.insert(v.begin() + count, 0x90);
    }

    int count{0};
    for (const auto itr : v)
    {
        if ((count >= 5) && (count < 10))
            std::cout << std::hex << std::showbase << itr << " ";
        else
            std::cout << std::dec << itr << " ";
        ++count;
    }
    std::cout << "\nv.size after insert =  " << v.size() << std::endl;
    std::cout << std::endl;
}
