// hw331_main.cpp
#ifndef HW331_CHECKTIMESTAMPS_H_
#include "hw331_checkTimestamps.h"
#endif
#include <iostream>
#include <fstream>
#include <istream>

int main(int argc, char const *argv[])
{
    if (argc == 1) {
    std::cout << "checkTimestamps <name_of_file>.txt" << std::endl;
    exit(1);
    }

    std::vector<CMidiPacket> vts;
    std::ifstream file (argv[1], std::ios::in);
    for (std::string line; std::getline(file, line); ){
        vts.push_back(CMidiPacket(line));
    }

  check_timestamps(vts);
}