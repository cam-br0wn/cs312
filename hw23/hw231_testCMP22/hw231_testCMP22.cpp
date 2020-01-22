// hw231_testCMP22.cpp
#include "hw222_CMidiPacket.h"

using namespace CMP22;

int main(int argc, char const *argv[])
{
	CMidiPacket mp(1000, 0x90, 60, 100);
	mp.print();
}