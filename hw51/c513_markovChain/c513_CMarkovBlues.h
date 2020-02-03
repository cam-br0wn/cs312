// c513_CMarkovBlues.h
#ifndef C513_CMARKOVBLUES_H_
#define C513_CMARKOVBLUES_H_

#include <iostream>
#include <vector>
#include <random>

extern std::random_device rd;
extern std::default_random_engine engine;

class CMarkovBlues
{
public:
	std::vector<int> vRBscale{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	int chooseMarkovNote(int note);
};

#endif // CMARKOVBLUES_H_