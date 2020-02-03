// hw331_main.cpp
#include <fstream>
#include <iostream>

using namespace std;

#ifndef HW331_CHECKTIMESTAMPS_H_
#include "hw331_checkTimestamps.h"
#endif

int main(int argc, char *argv[])
{
  string fileName_input = argv[1];
  createBadTimestampVector(fileName_input);
#if 0
  sort(begin(vts), end(vts));
#endif
  check_timestamps();
}