// Add boilerplate here

#ifndef HW234_SCIFISOUNDS_H_
#include "hw234_scifiSounds.h"
#endif
using namespace CMP22;

int main()
{
	const int kFIRST_DRUM = 35;
	const int kLAST_DRUM = 81;
	create_scifisounds_vector(kFIRST_DRUM, kLAST_DRUM);
	print_scifi();
}