// rand5.cpp
#include <iostream>
#include <random>
#include <cstdint>
#include <vector>
#include <algorithm>

int main()
{
  std::vector vscale{0, 2, 4, 7, 9, 12};
  std::vector<uint32_t> vnotes;
  const unsigned int v_size = vscale.size() - 1;

  std::random_device rd;
  std::default_random_engine dre{rd()};
  std::uniform_int_distribution<uint32_t> dist{0, v_size};

  for (int ix = 0; ix < 20; ++ix)
  {
    int n = dist(dre);
    int note = vscale.at(n) + 60;
    vnotes.push_back(note);
    std::cout << vnotes.at(ix) << " ";
  }
  std::cout << std::endl;
}
