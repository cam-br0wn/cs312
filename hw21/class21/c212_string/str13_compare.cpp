// str13_compare.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str1 = "CS 312 Winter 2020";
    std::string str2 = "CS 312 Winter 2020";
    std::string str3 = "cS 312 Winter 2020";
    std::cout << "str1 == str2 is " << std::boolalpha << (str1 == str2) << std::endl;
    std::cout << "str1 == str3 is " << std::boolalpha << (str1 == str3) << std::endl;
    std::cout << "str2 < str3 is  " << std::boolalpha << (str2 < str3) << std::endl;
    std::cout << "str3 > str1 is  " << std::boolalpha << (str3 > str1);
    std::cout << "\n// ascii C is 67, ascii c is 99, and 67 < 99" << std::endl;
}
