// v29.cpp
#include <iostream>
#include <vector>

int main()
{

    const std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> outvec;
    for ( auto ix = 0; ix < 7; ++ix )
        std::copy( v.begin(), v.end(), back_inserter( outvec ) );

    for ( auto itr : outvec )
        std::cout << itr << " ";
    std::cout << std::endl;

    // Sort
    std::sort( outvec.begin(), outvec.end() );
    for ( auto itr : outvec )
        std::cout << itr << " ";
    std::cout << std::endl;
}
