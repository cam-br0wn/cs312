//	c23_chronoFeatures.cpp
#include <iostream>
#include <chrono>

// From: CPL4 Section 35.2
void print_chrono_features()
{
  // namespace alias
  // sc means std::chrono
  namespace sc = std::chrono;
  std::cout << std::endl
            << "STD::CHRONO CLOCK FEATURES" << std::endl;
  std::cout << "===> system_clock" << std::endl;
  std::cout << "period numerator = " << sc::system_clock::period::num << std::endl;
  std::cout << "period denominator = " << sc::system_clock::period::den << std::endl;
  std::cout << "measures in microseconds" << std::endl;
  std::cout << "steady = " << std::boolalpha << sc::system_clock::is_steady << std::endl;

  std::cout << "\n===> high_resolution_clock" << std::endl;
  std::cout << "period numerator = " << sc::high_resolution_clock::period::num << std::endl;
  std::cout << "period denominator = " << sc::high_resolution_clock::period::den << std::endl;
  std::cout << "measures in nanoseconds" << std::endl;
  std::cout << "steady = " << std::boolalpha << sc::high_resolution_clock::is_steady << std::endl;

  std::cout << "\n===> steady_clock" << std::endl;
  std::cout << "period numerator = " << sc::steady_clock::period::num << std::endl;
  std::cout << "period denominator = " << sc::steady_clock::period::den << std::endl;
  std::cout << "measures in nanoseconds" << std::endl;
  std::cout << "steady = " << std::boolalpha << sc::steady_clock::is_steady << std::endl;
}

int main()
{
  print_chrono_features();
}
