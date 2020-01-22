// rand4.cpp
#include <iostream>
#include <random>
#include <cstdint>
#include <vector>
#include <algorithm>

int main()
{
  std::random_device rd;
  std::default_random_engine dre{rd()};
  std::uniform_int_distribution<uint32_t> dist{0, 1000};

  std::vector<uint32_t> v;
  for (int ix = 0; ix < 20; ++ix)
  {
    v.push_back(dist(dre));
  }

  // sorting is optional
  sort(v.begin(), v.end());

  // offset starting time to zero is optional
  for (auto itr : v)
  {
    std::cout << itr - v[0] << " ";
  }
  std::cout << std::endl;
}
