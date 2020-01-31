// hw331_checkTimestamps.cpp
#ifndef HW331_CHECKTIMESTAMPS_H_
#include "hw331_checkTimestamps.h"
#endif

#include <iostream>

// You implement
void check_timestamps(std::vector<CMidiPacket> vts)
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