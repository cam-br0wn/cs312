// rand1.cpp

#include <iostream>
#include <random>

void print10randomNumbers_1()
{
  // All sequences will be the same every time
  std::default_random_engine dre{}; // no std::random_device
  for (int ix = 0; ix < 10; ++ix)
  {
    std::cout << dre() << " ";
  }
  std::cout << std::endl;
}

void print10randomNumbers_2()
{
  // Different sequences every time
  std::random_device rd;
  std::default_random_engine dre{rd()}; // uses std::random_device
  for (int ix = 0; ix < 10; ++ix)
  {
    std::cout << dre() << " ";
  }
  std::cout << std::endl;
}

int main()
{
  const std::string kDivider(72, '-');
  std::cout << kDivider << '\n';
  print10randomNumbers_1();
  print10randomNumbers_2();
  std::cout << kDivider << '\n';
}
