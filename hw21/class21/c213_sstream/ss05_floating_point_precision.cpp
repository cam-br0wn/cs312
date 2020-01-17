// ss05_floating_point_precision.cpp

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::string pi_str = "3.141592653589793238";
    float fpi24 = std::stof(pi_str);
    double dpi24 = std::stod(pi_str);

    //std::setprecision(24)
    // float accurate to 6 decimals\n
    std::cout << "Precise pi =     "
              << pi_str << std::endl;
    std::cout << "Float pi   =     "
              << std::setprecision(24) << fpi24
              << " // float accurate to 6 decimals\n";

    // float accurate to 15 decimals\n
    std::cout << "\nPrecise pi =     "
              << pi_str << std::endl;
    std::cout << "Double pi  =     "
              << std::setprecision(24) << dpi24
              << " // double accurate to 15 decimals\n"
              << std::endl;
}
