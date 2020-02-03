/***************************************************************
 hw411_main.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw411
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-03
 TIME: 01:50:49
 ***************************************************************/
#include <iostream>

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

int main(int argc, char const *argv[])
{
  for (int n = 0; n < 12; ++n)
    std::cout << get_rand_int(0, 12) << " ";
  std::cout << '\n';

  for (int n = 0; n < 12; ++n)
    std::cout << get_rand_int(55, 67) << " ";
  std::cout << '\n';

  for (int n = 0; n < 12; ++n)
    std::cout << get_rand_int(0, 1) << " ";
  std::cout << '\n';

  return 0;
}