// str06_append_char.cpp

#include <iostream>
#include <string>
#include <vector>

void print4chars()
{
    for (auto m : {'a', 'b', 'c', 'd'})
        std::cout << m;
}

int main()
{
    std::string str;
    std::vector<char> vchar{'a', 'b', 'c', 'd'};

    print4chars();
    std::cout << std::endl;

    // first for loop
    for (int ix = 0; ix != vchar.size(); ++ix)
        str = str + vchar.at(ix) + ", ";
    std::cout << str << std::endl;

    // second for loop
    for (auto c : vchar)
        str += c;
    std::cout << str << std::endl;

    // third for loop
    str.clear();
    for (auto m : {'a', 'b', 'c', 'd'})
    {
        for (int i = 0; i < 4; ++i)
        {
            str += m;
        }
    }
    std::cout << str << std::endl;
}
