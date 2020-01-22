// v24.cpp
#include <iostream>
#include <vector>
// erase a single element
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto itr_begin = v.begin();
    v.erase( itr_begin + 5 );
    for ( const auto itr : v )
        std::cout << itr << " ";
    std::cout << "(erased 5)" << std::endl;
}
