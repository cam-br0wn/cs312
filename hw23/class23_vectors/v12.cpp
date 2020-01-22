// v12.cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 0;
    try
    {
        std::cout << "v.size() = " << v.size() << std::endl;
        x = v.at(25);
    }
    catch (const std::exception &e)
    {
        std::cout << "caught error: " << e.what() << std::endl;
        // return 0;
    }
    std::cout << "We got here\n";
}
