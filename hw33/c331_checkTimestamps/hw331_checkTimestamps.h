// hw331_checkTimestamps.h
#ifndef HW331_CHECKTIMESTAMPS_H_
#define HW331_CHECKTIMESTAMPS_H_

#ifndef HW322_CMIDIPACKET_H_
#include "hw322_CMidiPacket.h"
#endif

#include <vector>

using namespace CMP32;

extern std::vector<CMidiPacket> vts;

extern void createBadTimestampVector(std::string fileName);
extern void check_timestamps();

#endif // HW331_CHECKTIMESTAMPS_H_