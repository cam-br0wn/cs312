// hw421_CDelayMs.h
#ifndef HW421_CDELAY_MS_H_
#define HW421_CDELAY_MS_H_

#include <iostream>
#include <chrono>
#include <thread>

// idea from Stroustroup "A Tour of C++ 2nd Edition" page 200.

class CDelayMs
{
private:
  uint32_t delay_;
  bool print_;

  std::chrono::time_point<std::chrono::steady_clock> t0;
  std::chrono::time_point<std::chrono::steady_clock> t1;

  void milli_time();
  void delay();

public:
  static uint32_t s_tempo;

  CDelayMs(uint32_t ms, bool print = false);
  virtual ~CDelayMs();
};

#endif // HW421_CDELAY_MS_H_