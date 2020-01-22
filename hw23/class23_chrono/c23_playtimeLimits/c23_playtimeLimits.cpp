// c23_playtimeLimits.cpp
#include <iostream>
#include <limits>
#include <iomanip>

// Order dependent consts
const float millis_per_second = 1000.0;
const float millis_per_minute = millis_per_second * 60;
const float millis_per_hour = millis_per_minute * 60;
const float millis_per_day = millis_per_hour * 24;
const float millis_per_year = millis_per_day * 365;

template <typename T>
void print_time(T x)
{
  std::cout  << std::fixed << std::setprecision(2)
            << std::setw(12) << std::setfill(' ') << "size:" << std::setw(24)
            << std::setfill('.') << sizeof(T) << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "max:" << std::setw(24)
            << std::setfill('.') << std::numeric_limits<T>::max() << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "seconds:" << std::setw(24)
            << std::setfill('.') << x / millis_per_second << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "minutes:" << std::setw(24)
            << std::setfill('.') << x / millis_per_minute << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "hours:" << std::setw(24)
            << std::setfill('.') << x / millis_per_hour << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "years:" << std::setw(24)
            << std::setfill('.') << x / millis_per_year << std::endl;
  std::cout << std::endl;
}

int main()
{
// unsigned char does not display correctly using print_time()
  unsigned char x = 255;
  std::cout  << std::fixed << std::setprecision(2)
            << std::setw(12) << std::setfill(' ') << "size:" << std::setw(24)
            << std::setfill('.') << sizeof(x) << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "max:" << std::setw(24)
            << std::setfill('.') << +x << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "seconds:" << std::setw(24)
            << std::setfill('.') << x / millis_per_second << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "minutes:" << std::setw(24)
            << std::setfill('.') << x / millis_per_minute << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "hours:" << std::setw(24)
            << std::setfill('.') << x / millis_per_hour << std::endl;
  std::cout << std::setw(12) << std::setfill(' ') << "years:" << std::setw(24)
            << std::setfill('.') << x / millis_per_year << std::endl;
  std::cout << std::endl;

//   std::cout << "unsigned char max is 255 (displayed as ASCII)" << std::endl;
//   print_time(std::numeric_limits<unsigned short>::max());
  
  std::cout << "unsigned short\t" << std::endl;
  print_time(std::numeric_limits<unsigned short>::max());

  std::cout << "unsigned int\t" << std::endl;
  print_time(std::numeric_limits<unsigned int>::max());

  std::cout << "unsigned long\t" << std::endl;
  print_time(std::numeric_limits<unsigned long>::max());
}
