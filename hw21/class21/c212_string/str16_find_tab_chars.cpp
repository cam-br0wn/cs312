// str16_find_tab_chars.cpp

#include <iostream>
#include <string>
#include <vector>

int findTabs(std::string str, std::string searchStr)
{
    std::vector<int> vtabs;
    std::cout << "In findTabs()\nstr = " << str << std::endl;
    size_t ix = 0;
    ix = str.find(searchStr);
    while (ix != std::string::npos)
    {
        vtabs.push_back(ix);
        ix = str.find(searchStr, ix + searchStr.size());
    }
    std::cout << "vtabs.size " << vtabs.size() << std::endl;

    for (int n = 0; n < vtabs.size(); ++n)
    {
        std::cout << vtabs.at(n) << std::endl;
    }
    std::cout << std::endl;

    return vtabs.size();
}

int main()
{
    std::string str1 = "0\tc0\t11";
    std::string str2 = "1000\t90\t60\t100";
    int n1 = findTabs(str1, "\t");
    int n2 = findTabs(str2, "\t");

    std::cout << "In main()\nstr1 had " << n1 << " tab chars" << std::endl;
    std::cout << "str2 had " << n2 << " tab chars" << std::endl;
}
