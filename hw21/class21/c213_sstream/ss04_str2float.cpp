// ss04_str2float.cpp

#include <iostream>
#include <string>

int main()
{
    std::string pi_str = "3.141592653589793238";
    float fpi = std::stof(pi_str);
    std::cout << "float_pi =   " << fpi << std::endl;

    double dpi = std::stod(pi_str);
    std::cout << "double_pi  = " << dpi << std::endl;

    std::string pi_x = "333.141592653589793238";
    float fpx = std::stof(pi_x);
    std::cout << "float_pix =   " << fpx << std::endl;

    double dpx = std::stod(pi_x);
    std::cout << "double_pix  = " << dpx << std::endl;
}
