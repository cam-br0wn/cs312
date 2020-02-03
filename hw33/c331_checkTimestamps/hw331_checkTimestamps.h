// hw331_checkTimestamps.h
#ifndef HW331_CHECKTIMESTAMPS_H_
#define HW331_CHECKTIMESTAMPS_H_

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <vector>

using namespace CMP33;

extern std::vector<CMidiPacket> vts;

extern void createBadTimestampVector(std::string fileName);
extern void check_timestamps();

#endif // HW331_CHECKTIMESTAMPS_H_