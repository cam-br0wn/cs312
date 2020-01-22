// Add boilerplate here

#ifndef HW233_PLAYDRUMS_H_
#include "hw233_playdrums.h"
#endif
using namespace CMP22;

int main()
{
	const int kFIRST_DRUM = 35;
	const int kLAST_DRUM = 81;
	create_gmdrums_vector(kFIRST_DRUM, kLAST_DRUM);
	print_drums();
}