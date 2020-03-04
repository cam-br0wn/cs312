#include "sndfile.hh"
#include <iostream>
#include <vector>
#include <cmath> // for M_PI

// EITHER
typedef float MY_TYPE;
#define LIB_SF_FORMAT SF_FORMAT_FLOAT; // SF_FORMAT_MY_TYPE defiend in "sndfile.h"
// OR
// typedef double MY_TYPE;
// #define LIB_SF_FORMAT SF_FORMAT_DOUBLE; // SF_FORMAT_MY_TYPE defiend in "sndfile.h"
// END

const int FS = 44100;				// CD sample rate
const MY_TYPE T = 1.0 / FS; // sample period
const MY_TYPE k2PI = M_PI * 2.0;
const MY_TYPE k2PIT = k2PI * T;

std::vector<MY_TYPE> gen_square_phasor(MY_TYPE freq, MY_TYPE ampl, MY_TYPE secs)
{
	std::vector<MY_TYPE> v;
	MY_TYPE phzNow = 0;
	MY_TYPE phzIncr = k2PIT * freq;
	for (int n = 0; n < secs * FS; n++)
	{
		/*----------------------------------------------------
 Square wave = 1.0 if phznow <= pi
 Square wave = -1.0 if phzow > pi
 add sample to v
 increment phase now
 wrap around 2pi
 ----------------------------------------------------*/
		if(phzNow <= M_PI){
			v.push_back(1.0 * sin(freq));
		}
		else{
			v.push_back(-1.0 * sin(freq));
		}
		phzNow += phzIncr;
		if (phzNow > k2PI)
        {
            phzNow = phzNow - k2PI;
        }
	}
	// std::cout << "You need to implement gen_square_phasor(...)\n";
	return v;
}

bool samples2wavfile(const char *fname, const std::vector<MY_TYPE> &v)
{
	// code borrowed and modified from libsndfile example sndfilehandle.cc
	// mostly from create_file(...) and format from main()
	SndfileHandle file;
	const int channels = 1;
	const int srate = FS;
	const int format = SF_FORMAT_WAV | LIB_SF_FORMAT;

	file = SndfileHandle(fname, SFM_WRITE, format, channels, srate);

	// using vector instead of buffer array
	// C++ vector elements are stored in contiguous memory, same as array
	// &v[0] is pointer to first element of vector
	file.write(&v[0], v.size());
	return true;
}

int main(int argc, char *argv[])
{
	std::vector<MY_TYPE> vsamps = gen_square_phasor(1000.0, 1.0, 1.5);
	samples2wavfile("hw821_gensquare_phasor_1000Hz.wav", vsamps);
	return 0;
}