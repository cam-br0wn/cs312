// c513_CMarkovBlues.cpp
#ifndef C513_CMARKOVBLUES_H_
#include "c513_CMarkovBlues.h"
#endif

#include <iostream>
#include <vector>
#include <random>

int CMarkovBlues::chooseMarkovNote(int note)
{
	// rock blues
	// const std::vector<int> kweigh{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	const std::vector<int> k0weights{5, 0, 0, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0};
	const std::vector<int> k3weights{0, 0, 0, 2, 4, 0, 0, 4, 0, 0, 0, 0, 0};
	const std::vector<int> k4weights{0, 0, 0, 2, 3, 0, 0, 5, 0, 0, 0, 0, 0};
	const std::vector<int> k7weights{0, 0, 0, 0, 3, 0, 0, 4, 0, 0, 3, 0, 0};
	const std::vector<int> k9weights{0, 0, 0, 0, 0, 0, 0, 4, 0, 1, 5, 0, 0};
	const std::vector<int> k10weights{0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 2, 0, 4};
	const std::vector<int> k12weights{0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 3, 0, 3};

	std::random_device rd;
	std::default_random_engine engine(rd());

	std::discrete_distribution<int> distribution_k0(k0weights.begin(), k0weights.end());
	std::discrete_distribution<int> distribution_k3(k3weights.begin(), k3weights.end());
	std::discrete_distribution<int> distribution_k4(k4weights.begin(), k4weights.end());
	std::discrete_distribution<int> distribution_k7(k7weights.begin(), k7weights.end());
	std::discrete_distribution<int> distribution_k9(k9weights.begin(), k9weights.end());
	std::discrete_distribution<int> distribution_k10(k10weights.begin(), k10weights.end());
	std::discrete_distribution<int> distribution_k12(k12weights.begin(), k12weights.end());

	int n;
	switch (note)
	{
	case 0:
		n = distribution_k0(engine);
		break;

	case 3:
		n = distribution_k3(engine);
		break;

	case 4:
		n = distribution_k4(engine);
		break;

	case 7:
		n = distribution_k7(engine);
		break;

	case 9:
		n = distribution_k9(engine);
		break;

	case 10:
		n = distribution_k10(engine);
		break;

	case 12:
		n = distribution_k12(engine);
		break;

	default:
		n = distribution_k0(engine);
		break;
	}
	return n;
}