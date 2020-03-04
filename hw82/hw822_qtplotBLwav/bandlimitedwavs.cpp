#ifndef BANDLIMITEDWAVS_H
#include "bandlimitedwavs.h"
#endif

#include <QDebug>

#include <numeric>

const MY_TYPE k2overPI = 2 / M_PI;
const MY_TYPE k4overPI = 4 / M_PI;
const MY_TYPE k8overPIsquared = 8 / ( M_PI * M_PI );

void doSineCallback( unsigned int nBufferFrames, MY_TYPE* buffer )
{
    static int countsin = 0;
    for ( unsigned int n = 0; n < nBufferFrames; n++ )
    {
        MY_TYPE val = hSlider_ampl * sin( k2PIT * hSlider_freq * countsin );
        *buffer++ = val;
        vsamps.push_back( val );
        countsin++;
    }
}

void doPlotSine()
{
    // almost the same as the doSineCallback(...) callback function
    // however it is not called repeatedly by the callback function
    // it fills the plot_buffer variable instead of vector vsamps

    int count{1};
    for ( unsigned int n = 0; n < kRTABUFFER_SZ; n++ )
    {
        MY_TYPE val = hSlider_ampl * sin( k2PIT * hSlider_freq * count );
        plot_buffer[ n ] = val;
        count++;
    }
}

////////////////////////////////////////////////////////
// JE code you can use for to figure out the other waveforms
////////////////////////////////////////////////////////
// This function calculates a single sample for harmonic (n * count)
// using the Fourier Series formula shown on the web page.
MY_TYPE calcSawDownHarmonics( int count )
{
    MY_TYPE samp{0};
    MY_TYPE sum{0};
    std::vector<MY_TYPE> v;

    for ( int n = 1; n <= hSlider_numHarmonics; ++n )
    {
        samp = ( 1.0 / n ) * hSlider_ampl * sin( k2PIT * hSlider_freq * n * count );
        v.push_back( samp );
    }
    // add up all the harmonics and multiply by k2overPI
    sum = k2overPI * std::accumulate( v.begin(), v.end(), 0.0 );
    return sum;
}

void doSawDownBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer )
{
    // this function is called repeatedly by the rtaudio callback function
    // countSawDownCallbacks is declared static so the next time it's called
    // it can remember its location for the vsamps vector

    static int countSawDownCallbacks = 1;
    MY_TYPE sum{0};

    // nBufferFrames = kRTABUFFER_SZ = numSamples in callback buffer
    unsigned int numSamplesInBuffer = nBufferFrames;
    for ( unsigned int n = 0; n < numSamplesInBuffer; ++n )
    {
        // calculate the Harmonic series for this trip through the callback function
        sum = calcSawDownHarmonics( countSawDownCallbacks );

        // buffer is a pointer address
        // *buffer is the value stored at that address
        // buffer++ advances the buffer pointer by the size of the objects it contains (MY_TYPE)
        *buffer = sum;
        buffer++;

        // In other C++ functions it's easier to deal with vectors than with pointer arithmetic
        vsamps.push_back( sum );

        // finished one trip through the callback function, increment countSawDownCallbacks
        countSawDownCallbacks++;
    }
}

void doPlotSawDownBL()
{
    // uses the calcSawDownHarmonics() function
    // it fills the plot_buffer variable instead of vector vsamps
    // it is not part of the callback function

    int count = 0;
    MY_TYPE sum{0};
    for ( unsigned int n = 0; n < kRTABUFFER_SZ; ++n )
    {
        sum = calcSawDownHarmonics( count );
        plot_buffer[ n ] = sum;
        ++count;
    }
}
////////////////////////////////////////////////////////
// end JE code
////////////////////////////////////////////////////////

MY_TYPE calcSquareHarmonics( int count )
{
    // figure it out
//    qDebug() << "You need to implement the calcSquareHarmonics() function";
    MY_TYPE samp{0};
    MY_TYPE sum{0};
    std::vector<MY_TYPE> v;

    for ( int k = 1; k <= hSlider_numHarmonics; ++k )
    {
        samp = ( pow(1.0, (2 *k - 1) ) / (2 * k - 1) ) * hSlider_ampl * sin( k2PIT * hSlider_freq * (2 * k - 1) * count );
        v.push_back( samp );
    }
    // add up all the harmonics and multiply by k2overPI
    sum = k4overPI * std::accumulate( v.begin(), v.end(), 0.0 );
    return sum;
}

void doSquareBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer )
{
    // this function is called repeatedly by the rtaudio callback function
    // countSquareCallbacks is declared static so the next time it's called
    // it can remember its location for the vsamps vector

    static int countSquareCallbacks = 1;
    MY_TYPE sum{0};

    // nBufferFrames = kRTABUFFER_SZ = numSamples in callback buffer
    unsigned int numSamplesInBuffer = nBufferFrames; // a reminder that for mono files nBufferFrames == numberSamples
    for ( unsigned int n = 0; n < numSamplesInBuffer; ++n )
    {
        // calculate the SawDown Harmonic series for this trip through the callback
        sum = calcSquareHarmonics( countSquareCallbacks );

        // buffer is a pointer address
        // *buffer is the value stored at that address
        // buffer++ advances the buffer pointer by the size of the objects it contains (MY_TYPE)
        *buffer = sum;
        buffer++;
        *buffer = sum;
        buffer++;

        // Other C++ functions like vectors better than buffers and pointer arithmetic
        vsamps.push_back( sum );

        // finished one trip through the callback function
        // increment countSawDownCallbacks
        countSquareCallbacks++;
    }
}

void doPlotSquareBL()
{
    // uses the calcSquareHarmonics() function
    // it fills the plot_buffer variable instead of vector vsamps
    // it is not part of the callback function

    int count = 0;
    MY_TYPE sum{0};
    for ( unsigned int n = 0; n < kRTABUFFER_SZ; ++n )
    {
        sum = calcSquareHarmonics( count );
        plot_buffer[ n ] = sum;
        ++count;
    }
}

MY_TYPE calcSawUpHarmonics( int count )
{
    // figure it out
    MY_TYPE samp{0};
    MY_TYPE sum{0};
    std::vector<MY_TYPE> v;

    for ( int k = 1; k <= hSlider_numHarmonics; ++k )
    {
        samp = ( pow(-1.0, (k - 1) ) / k ) * hSlider_ampl * sin( k2PIT * hSlider_freq * k * count );
        v.push_back( samp );
    }
    // add up all the harmonics and multiply by k2overPI
    sum = k2overPI * std::accumulate( v.begin(), v.end(), 0.0 );
    return sum;
}

void doSawUpBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer )
{
    // this function is called repeatedly by the rtaudio callback function
    // countSquareCallbacks is declared static so the next time it's called
    // it can remember its location for the vsamps vector

    static int countSawUpCallbacks = 1;
    MY_TYPE sum{0};

    // nBufferFrames = kRTABUFFER_SZ = numSamples in callback buffer
    unsigned int numSamplesInBuffer = nBufferFrames; // a reminder that for mono files nBufferFrames == numberSamples
    for ( unsigned int n = 0; n < numSamplesInBuffer; ++n )
    {
        // calculate the SawDown Harmonic series for this trip through the callback
        sum = calcSawUpHarmonics( countSawUpCallbacks );

        // buffer is a pointer address
        // *buffer is the value stored at that address
        // buffer++ advances the buffer pointer by the size of the objects it contains (MY_TYPE)
        *buffer = sum;
        buffer++;
        *buffer = sum;
        buffer++;

        // Other C++ functions like vectors better than buffers and pointer arithmetic
        vsamps.push_back( sum );

        // finished one trip through the callback function
        // increment countSawDownCallbacks
        countSawUpCallbacks++;
    }
}

void doPlotSawUpBL()
{
    // uses the calcSawDownHarmonics() function
    // it fills the plot_buffer variable instead of vector vsamps
    // it is not part of the callback function

    int count = 0;
    MY_TYPE sum{0};
    for ( unsigned int n = 0; n < kRTABUFFER_SZ; ++n )
    {
        sum = calcSawUpHarmonics( count );
        plot_buffer[ n ] = sum;
        ++count;
    }
}

MY_TYPE calcTriangleHarmonics( int count )
{
    // figure it out
    MY_TYPE samp{0};
    MY_TYPE sum{0};
    std::vector<MY_TYPE> v;

    for ( int k = 1; k <= hSlider_numHarmonics; ++k )
    {
        samp = ( pow(-1.0, (k + 1) ) / pow((2 * k - 1), 2) ) * hSlider_ampl * sin( k2PIT * hSlider_freq * (2 * k - 1) * count );
        v.push_back( samp );
    }
    // add up all the harmonics and multiply by 2 * (k2overPI ^ 2) == (8 / pi^2)
    sum = k8overPIsquared * std::accumulate( v.begin(), v.end(), 0.0 );
    return sum;
}

void doTriangleBLCallback( unsigned int nBufferFrames, MY_TYPE* buffer )
{
    // this function is called repeatedly by the rtaudio callback function
    // countTriangleCallbacks is declared static so the next time it's called
    // it can remember its location for the vsamps vector

    static int countTriangleCallbacks = 1;
    MY_TYPE sum{0};

    // nBufferFrames = kRTABUFFER_SZ = numSamples in callback buffer
    unsigned int numSamplesInBuffer = nBufferFrames; // a reminder that for mono files nBufferFrames == numberSamples
    for ( unsigned int n = 0; n < numSamplesInBuffer; ++n )
    {
        // calculate the Triangle Harmonic series for this trip through the callback
        sum = calcTriangleHarmonics( countTriangleCallbacks );

        // buffer is a pointer address
        // *buffer is the value stored at that address
        // buffer++ advances the buffer pointer by the size of the objects it contains (MY_TYPE)
        *buffer = sum;
        buffer++;
        *buffer = sum;
        buffer++;

        // Other C++ functions like vectors better than buffers and pointer arithmetic
        vsamps.push_back( sum );

        // finished one trip through the callback function
        // increment countTriangleCallbacks
        countTriangleCallbacks++;
    }
}

void doPlotTriangleBL()
{
    // uses the calcTriangleHarmonics() function
    // it fills the plot_buffer variable instead of vector vsamps
    // it is not part of the callback function

    int count = 0;
    MY_TYPE sum{0};
    for ( unsigned int n = 0; n < kRTABUFFER_SZ; ++n )
    {
        sum = calcTriangleHarmonics( count );
        plot_buffer[ n ] = sum;
        ++count;
    }
}
