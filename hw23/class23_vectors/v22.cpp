// v22.cpp
#include <iostream>
#include <numeric> // accumulate()
#include <vector>

// print the sum of a vector of ints using std::accumulate
int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 100; ++i)
        v.push_back(i);
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "sum of 1..100 = " << sum << std::endl;
}
