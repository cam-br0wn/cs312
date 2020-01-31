// hw331_checkTimestamps.h
#ifndef HW331_CHECKTIMESTAMPS_H_
#define HW331_CHECKTIMESTAMPS_H_

#ifndef hw322_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <vector>

using namespace CMP32;

extern std::vector<CMidiPacket> vts;

extern void createBadTimestampVector();
extern void check_timestamps();

#endif // HW331_CHECKTIMESTAMPS_H_