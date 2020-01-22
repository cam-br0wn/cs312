// v21.cpp
#include <algorithm> // for_each()
#include <iostream>
#include <vector>

// a C++ function object
struct Squared
{
    int sqr;
    // constructor
    Squared() : sqr{0} {}
    // overload function operator ()
    void operator()(int n)
    {
        sqr = n * n;
        std::cout << sqr << " ";
    }
};

// print element cubed using for_each and a lambda function
int main()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // method 1
    // print element squared using a function object
    std::for_each(v.begin(), v.end(), Squared());
    std::cout << std::endl;

    // method 2
    // print element squared using for_each and a lambda function
    std::for_each(v.begin(), v.end(),
                  [](int x) { std::cout << x * x << " "; });
    std::cout << std::endl;
}
