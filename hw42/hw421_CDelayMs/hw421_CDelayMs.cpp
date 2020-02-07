/***************************************************************
 hw421_CDelayMs.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw421
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-02-06
 TIME: 19:19:19
 ***************************************************************/
#ifndef HW421_CDELAY_MS_H_
#include "hw421_CDelayMs.h"
#endif

uint32_t CDelayMs::s_tempo = 60;

void CDelayMs::milli_time()
{
  t1 = std::chrono::steady_clock::now();
  std::cout << "# ms:\t\t\t\t";
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << '\n';
}

void CDelayMs::delay()
{
  uint32_t dly = delay_ * 60 / s_tempo;
  std::this_thread::sleep_for(std::chrono::milliseconds(dly));
}

CDelayMs::CDelayMs(uint32_t ms, bool print) : delay_{ms}, print_{print}
{
  t0 = std::chrono::steady_clock::now();
  delay();
}

CDelayMs::~CDelayMs()
{
  if (print_)
    milli_time();
}