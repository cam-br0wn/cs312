// rand3.cpp
#include <iostream>
#include <random>
#include <cstdint>

int main()
{
  std::random_device rd;
  std::default_random_engine dre{rd()};
  std::uniform_int_distribution<uint8_t> dist{48, 72};
  for (int ix = 0; ix < 20; ++ix)
  {
    std::cout << dist(dre) << " ";
  }
  std::cout << std::endl;

  for (int ix = 0; ix < 20; ++ix)
  {
    std::cout << +dist(dre) << " "; // convert int8_t to int16_t for printing
  }
  std::cout << std::endl;
}
