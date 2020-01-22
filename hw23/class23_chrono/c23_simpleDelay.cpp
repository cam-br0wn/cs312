// c23_simpleDelay.cpp
#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

// From: A Tour of C++ 2nd Edition Section 15.6, page 200.
using namespace std::chrono;

void simple_delay(int delay)
{
  auto t0 = high_resolution_clock::now();
  std::this_thread::sleep_for(milliseconds(delay));
  auto t1 = high_resolution_clock::now();

  // std::cout << duration_cast<nanoseconds>(t1 - t0).count() << " nanoseconds passed\n";
  std::cout << duration_cast<microseconds>(t1 - t0).count() << " microseconds passed\n";
  // std::cout << duration_cast<milliseconds>(t1 - t0).count() << " milliseconds passed\n";
}

int main()
{
  std::cout << "==== 1000 ms" << std::endl;
  for (int ix = 0; ix < 10; ++ix)
    simple_delay(1000); // 1 second

  std::cout << "==== 500 ms" << std::endl;
  for (int ix = 0; ix < 10; ++ix)
    simple_delay(500); // 500 ms

  std::cout << "==== 100 ms" << std::endl;
  for (int ix = 0; ix < 10; ++ix)
    simple_delay(100); // 100 ms

  std::cout << "==== 1 ms" << std::endl;
  for (int ix = 0; ix < 10; ++ix)
    simple_delay(1); // 1 ms
}
