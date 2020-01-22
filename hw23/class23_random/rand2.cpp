// rand2.cpp
#include <iostream>
#include <random>

// Mersenne Twister generator
// std:: mt19937
int main()
{
  std::random_device rd;
  std::mt19937 mt_gen{rd()};
  for (int ix = 0; ix < 10; ++ix)
  {
    std::cout << mt_gen() << " ";
  }
  std::cout << std::endl;
}
