// v01.cpp
#include <iostream>
#include <vector>

// initialize vector with 5 values
int main()
{
    std::vector<int> v = {0, 2, 4, 6, 8};
    for ( int ix = 0; ix < v.size(); ++ix )
        std::cout << v[ ix ] << " ";
    std::cout << std::endl;
}
