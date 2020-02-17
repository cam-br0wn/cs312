#include <random>
#include <iostream>
 
#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

int get_rand_int(int lo, int hi)
{
    // retrieved from https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(lo, hi);
 
    return dis(gen);
}