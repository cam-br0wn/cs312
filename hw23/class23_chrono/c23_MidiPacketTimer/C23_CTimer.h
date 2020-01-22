// C23_Timer.h

#ifndef C23_CTIMER_H_
#define C23_CTIMER_H_

#include <iostream>
#include <chrono>

namespace CS312
{
class CTimer
{
private:
	bool print_;
	// start time t0
	std::chrono::time_point<std::chrono::high_resolution_clock> t0;
	// stop time t1;
	std::chrono::time_point<std::chrono::high_resolution_clock> t1;

public:
	CTimer(bool print) : print_{print}
	{
		t0 = std::chrono::high_resolution_clock::now();
	}

	virtual ~CTimer()
	{
		t1 = std::chrono::high_resolution_clock::now();
		if (print_)
			milli_time();
	}

	void reset()
	{
		t0 = std::chrono::high_resolution_clock::now();
	}

	void milli_time()
	{
		t1 = std::chrono::high_resolution_clock::now();
		std::cout << "#Time ms:\t";
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << '\n';
	}
};
} // namespace CS312

#endif // c23_CTIMER_H_
