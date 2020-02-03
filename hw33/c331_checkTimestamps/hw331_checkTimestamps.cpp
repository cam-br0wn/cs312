// hw331_checkTimestamps.cpp
#ifndef HW331_CHECKTIMESTAMPS_H_
#include "hw331_checkTimestamps.h"
#endif

#include <iostream>
#include <fstream>

std::vector<CMidiPacket> vts;

/*
void createBadTimestampVector()
{
    CMidiPacket mp;
    vts.push_back(mp = {0, 0xc0, 11});
    vts.push_back(mp = {0, 0x90, 69, 100});
    vts.push_back(mp = {1000, 0x80, 69, 0});
    vts.push_back(mp = {1000, 0x90, 64, 100});
    vts.push_back(mp = {1125, 0x80, 64, 0});
    vts.push_back(mp = {1125, 0x90, 69, 100});
    vts.push_back(mp = {1250, 0x80, 69, 0});
    vts.push_back(mp = {1250, 0x90, 64, 100});
    vts.push_back(mp = {1375, 0x80, 64, 0});
    vts.push_back(mp = {1375, 0x90, 67, 100});
    vts.push_back(mp = {2375, 0x80, 67, 0});
    vts.push_back(mp = {2375, 0x90, 69, 100});
    vts.push_back(mp = {2875, 0x80, 69, 0});
    vts.push_back(mp = {2875, 0x90, 64, 100});
    vts.push_back(mp = {3875, 0x80, 64, 0});
    vts.push_back(mp = {3875, 0x90, 67, 100});
    vts.push_back(mp = {4125, 0x80, 67, 0});
    vts.push_back(mp = {4125, 0x90, 67, 100});
    vts.push_back(mp = {4375, 0x80, 67, 0});
    vts.push_back(mp = {4375, 0x90, 64, 100});
    vts.push_back(mp = {4875, 0x80, 64, 0});
    vts.push_back(mp = {4875, 0x90, 72, 100});
    vts.push_back(mp = {5375, 0x80, 72, 0});
    vts.push_back(mp = {5365, 0x90, 64, 100});
    vts.push_back(mp = {5500, 0x80, 64, 0});
    vts.push_back(mp = {5500, 0x90, 67, 100});
    vts.push_back(mp = {5750, 0x80, 67, 0});
    vts.push_back(mp = {5750, 0x90, 60, 100});
    vts.push_back(mp = {6000, 0x80, 60, 0});
    vts.push_back(mp = {6000, 0x90, 72, 100});
    vts.push_back(mp = {7000, 0x80, 72, 0});
    vts.push_back(mp = {7000, 0x90, 64, 100});
    vts.push_back(mp = {7250, 0x80, 64, 0});
    vts.push_back(mp = {7250, 0x90, 69, 100});
    vts.push_back(mp = {7750, 0x80, 69, 0});
    vts.push_back(mp = {7750, 0x90, 72, 100});
    vts.push_back(mp = {8250, 0x80, 72, 0});
    vts.push_back(mp = {8250, 0x90, 64, 100});
    vts.push_back(mp = {8375, 0x80, 64, 0});
    vts.push_back(mp = {8375, 0x90, 67, 100});
    vts.push_back(mp = {8625, 0x80, 67, 0});
    vts.push_back(mp = {8625, 0x90, 64, 100});
    vts.push_back(mp = {8750, 0x80, 64, 0});
    vts.push_back(mp = {8650, 0x90, 67, 100});
    vts.push_back(mp = {8875, 0x80, 67, 0});
    vts.push_back(mp = {8875, 0x90, 69, 100});
    vts.push_back(mp = {9375, 0x80, 69, 0});
    vts.push_back(mp = {9375, 0x90, 60, 100});
    vts.push_back(mp = {9500, 0x80, 60, 0});
    vts.push_back(mp = {9500, 0x90, 67, 100});
    vts.push_back(mp = {9750, 0x80, 67, 0});
    vts.push_back(mp = {9750, 0x90, 62, 100});
    vts.push_back(mp = {10750, 0x80, 62, 0});
    vts.push_back(mp = {10750, 0x90, 62, 100});
    vts.push_back(mp = {11750, 0x80, 62, 0});
    vts.push_back(mp = {11750, 0x90, 64, 100});
    vts.push_back(mp = {12750, 0x80, 64, 0});
    vts.push_back(mp = {12750, 0x90, 72, 100});
    vts.push_back(mp = {13750, 0x80, 72, 0});
    vts.push_back(mp = {13750, 0x90, 69, 100});
    vts.push_back(mp = {14250, 0x80, 69, 0});
    vts.push_back(mp = {14250, 0x90, 64, 100});
    vts.push_back(mp = {14375, 0x80, 64, 0});
    vts.push_back(mp = {14375, 0x90, 62, 100});
    vts.push_back(mp = {14500, 0x80, 62, 0});
    vts.push_back(mp = {14500, 0x90, 69, 100});
    vts.push_back(mp = {14625, 0x80, 69, 0});
    vts.push_back(mp = {14625, 0x90, 69, 100});
    vts.push_back(mp = {15625, 0x80, 69, 0});
    vts.push_back(mp = {15625, 0x90, 60, 100});
    vts.push_back(mp = {15875, 0x80, 60, 0});
    vts.push_back(mp = {15875, 0x90, 72, 100});
    vts.push_back(mp = {16125, 0x80, 72, 0});
    vts.push_back(mp = {16125, 0x90, 67, 100});
    vts.push_back(mp = {16625, 0x80, 67, 0});
    vts.push_back(mp = {16625, 0x90, 62, 100});
    vts.push_back(mp = {16750, 0x80, 62, 0});
    vts.push_back(mp = {16750, 0x90, 60, 100});
    vts.push_back(mp = {16875, 0x80, 60, 0});
    vts.push_back(mp = {16875, 0x90, 69, 100});
    vts.push_back(mp = {17000, 0x80, 69, 0});
    vts.push_back(mp = {17000, 0x90, 72, 100});
    vts.push_back(mp = {17125, 0x80, 72, 0});
    vts.push_back(mp = {17125, 0x90, 72, 100});
    vts.push_back(mp = {17250, 0x80, 72, 0});
    vts.push_back(mp = {17250, 0x90, 67, 100});
    vts.push_back(mp = {17500, 0x80, 67, 0});
    vts.push_back(mp = {17500, 0x90, 72, 100});
    vts.push_back(mp = {16750, 0x80, 72, 0});
    vts.push_back(mp = {17750, 0x90, 69, 100});
    vts.push_back(mp = {18000, 0x80, 69, 0});
    vts.push_back(mp = {18000, 0x90, 72, 100});
    vts.push_back(mp = {18250, 0x80, 72, 0});
    vts.push_back(mp = {18250, 0x90, 62, 100});
    vts.push_back(mp = {18375, 0x80, 62, 0});
    vts.push_back(mp = {18375, 0x90, 72, 100});
    vts.push_back(mp = {18625, 0x80, 72, 0});
    vts.push_back(mp = {18625, 0x90, 64, 100});
    vts.push_back(mp = {18750, 0x80, 64, 0});
    vts.push_back(mp = {18750, 0x90, 67, 100});
    vts.push_back(mp = {19000, 0x80, 67, 0});
}
*/

void createBadTimestampVector(std::string fileName){
    std::ifstream inFile;

    inFile.open(fileName);

    std::string line;
    CMidiPacket mp;

    while(std::getline(inFile, line)){
        mp = {line};
        vts.push_back(mp);
    }
    inFile.close();
}

// You implement
void check_timestamps()
{
    uint32_t prevTs = 0;
    uint32_t nowTs = 0;

    for (auto itr : vts)
    {
        nowTs = itr.get_timestamp();
        if (nowTs < prevTs) {
            std::cout << "### " << nowTs << " Timestamp out or order \n";
        }
        std::cout << itr.to_string() << std::endl;
        prevTs = nowTs;
    }
}