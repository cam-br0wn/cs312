// hw331_checkTimestamps.cpp
#ifndef HW331_CHECKTIMESTAMPS_H_
#include "hw331_checkTimestamps.h"
#endif

#include <iostream>
#include <fstream>
#include <iterator>

std::vector<CMP33::CMidiPacket> vts;

void createBadTimestampVector(std::string fileName)
{
    std::string line;
    std::ifstream inFile(fileName);

    CMP33::CMidiPacket mp;

    while (std::getline(inFile, line))
    {
        mp = CMP33::CMidiPacket(line);
        vts.push_back(mp);
    }
    //inFile.close();
}

// You implement
void check_timestamps()
{
    uint32_t prevTs = 0;
    uint32_t nowTs = 0;

    for (auto itr : vts)
    {
        nowTs = itr.get_timestamp();
        if (nowTs < prevTs)
        {
            std::cout << "### " << nowTs << " Timestamp out or order \n";
        }
        std::cout << itr.to_string() << std::endl;
        prevTs = nowTs;
    }
}