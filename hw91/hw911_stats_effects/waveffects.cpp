#ifndef WAVEFFECTS_H
#include "waveffects.h"
#endif

#ifndef WAVSTATS_H
#include "wavstats.h" // for vsamps
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

#include <QDoubleSpinBox>
#include <QMessageBox>
#include <QtDebug>

#include <cmath>
#include <iostream>

MY_TYPE normalize_dBval;
MY_TYPE changeSpeed_rate{1.0};
MY_TYPE amplify_maxSample;
int echo_num{4};
MY_TYPE echo_delay{300};
MY_TYPE echo_damp{.5};

int snip_minLen{200};
int snip_maxLen{441};
int snip_reps{15};

std::vector<MY_TYPE> veffect;

void doRemoveDC()
{
    veffect = vsamps;
    MY_TYPE dc = getDCoffset( veffect );
    for ( size_t n = 0; n < veffect.size(); ++n ) {
        veffect.at( n ) += -dc;
    }
}

void doNormalize( MY_TYPE val )
{
//    The val parameter is passed in from ui->doubleSpinBox_normalize->value()
//    Set veffect = vsamps
    veffect = vsamps;
   // get file peak dB
     MY_TYPE peakdB = getPeakdB(veffect);
    //ui_dB = slider value to dB
    MY_TYPE ui_dB = val;

   // calculate the dB difference between ui_dB and file peak dB (subtract dBs)
    MY_TYPE difference = peakdB - ui_dB;
   // convert dB difference to amplitude
     MY_TYPE amp = (10 * difference)/20;
   //  multiply every sample by new amplitude
    for (int i = 0; i < veffect.size(); i++) {
        veffect.at(i) = veffect.at(i) * amp;
    }
}

void doAmplify( MY_TYPE val )
{

//    The val parameter is passed in from ui->doubleSpinBox_amplify->value()
//    Set veffect = vsamps
    veffect = vsamps;
//    get file max sample
    MY_TYPE fileMax = getMaxSample(veffect);
//    ui_amp = slider value
    MY_TYPE ui_amp = val;
//    calculate dB ratio between ui_amp and file amp
    MY_TYPE dbRatio = ui_amp/fileMax;
//    convert dB ratio to amplitude
    MY_TYPE amp = (10 * (dbRatio/20));

//    multiply every sample by new amplitude
    for (int i = 0; i < veffect.size(); i++) {
        veffect.at(i) = veffect.at(i) * amp;
    }
}

void doReverse()
{
    std::reverse(vsamps.begin(), vsamps.end());
    veffect = vsamps;
}

void doEchos()
{
//  calculate the number samples needed for the GUI delay of Delay milliseconds
//  multiply that number by the GUI number of echos
    MY_TYPE num_samples = echo_delay;
    MY_TYPE num_echos = num_samples * echo_num;

//  create GUI number of echo vectors of length vsamps.size() + the samples needed for GUI number of echos
    std::vector<MY_TYPE> vector1(vsamps.size() + num_echos);
    std::vector<MY_TYPE> vector2(vsamps.size() + num_echos);
    std::vector<MY_TYPE> vector3(vsamps.size() + num_echos);
    std::vector<MY_TYPE> vector4(vsamps.size() + num_echos);

//      set all samples in each of the vector 1 to zero
    for (int i = 0; i < vector1.size(); i++) {
        vector1.at(i) = 0;
    }

//  set the other vectors = vector 1 (all zeros)
    vector2 = vector1;
    vector3 = vector1;
    vector4 = vector1;


    //      as you're copying the samples adjust the amplitude reduction accordingly
    //      new vector 1 = original amplitude
    //      new vector 2 = original amplitude multiplied by damping reduction
    //      new vector 3 = original amplitude times multiplied by 2 times reduction
    //      new vector 4 = original amplitude times multiplied by 3 times reduction

//  copy vsamps into new vector 1 beginning at sample[0]


//   check veffect for clipping

}

void doChangeSpeed( MY_TYPE rate )
{

       // Variable names I used - you can make up your own
       // Try to use names that someone else reading the code would understand right away
        MY_TYPE indx_now{0};
        MY_TYPE indx_prev{0};
        MY_TYPE outsamp{0};
        size_t file_sz;
        size_t new_sz;
        size_t indx_left;
        size_t indx_right;
        MY_TYPE indx_RL;
        MY_TYPE samp_RL;

//        parameter rate is the speed we're reading through vsamps
//            rate = 1.0 is the normal sample rate
//            rate = 2.0 we're reading every other sample, new_sz = 0.5 * file_sz
//            rate = 0.5 we're reading sample[n], then computing a sample
//                    half way between sample[n] and sample[n+1]
//                    then reading sample[n+1], new_sz = 2 * file_sz

//        calc file_sz equals vsamps size
        file_sz = vsamps.size();
//        calc new_sz = file_sz / rate
        new_sz = file_sz / rate;
//        resize veffect to new_sz
        veffect.resize(new_sz);

//        for loop n =  0 to new_sz
        for (int i = 0; i < new_sz; i++) {
            // set indx_now to fmod(indx_prev + rate, file_sz)
            // set indx_left to floor of indx_now
            indx_now = std::fmod(indx_prev + rate, file_sz);
            indx_left = std::floor(indx_now);

            // while indx_left >= file_sz
            // indx_left %= file_sz
            while (indx_left >= file_sz) {
                indx_left %= file_sz;
            }
            //   set indx_rigth = indx_left + 1;
            //   while indx_right >= file_sz
            //      idx_right %= file_sz
            indx_right = indx_left + 1;
            while (indx_right >= file_sz) {
                indx_right %= file_sz;
            }

            //  set indx_RL = indx_right - indx_left
            //  set samp_RL = vsamps indx_right = vsamps indx_left
            //  outsamp = vsamps indx_left + (indx_now - indx_left) * sampRL/indxRL
            //  veffect at n = outsamp;
            //  indx_prev = indx_now
            indx_RL = indx_right - indx_left;
            samp_RL = vsamps.at(indx_right);
            indx_right = vsamps.at(indx_left);
            outsamp = vsamps.at(indx_left) + (indx_now - indx_left) * samp_RL/indx_RL;

            veffect.at(i) = outsamp;
            indx_prev = indx_now;
        }
}

void doRandomSnips( QLabel* label )
{

        // snip_maxLen and snip_reps are set in mainwindow.cpp widget slot functions
        int count{0};
        veffect.clear();
        veffect.reserve( 2 * 60 * FS ); // two minutes
        std::vector<MY_TYPE> vsnip;
        vsnip.reserve( 2 * 60 * FS ); // two minutes

        int sz = static_cast<int>( vsamps.size() );
        int numSnips = 300;

        for ( int n = 0; n < numSnips; ++n )
        {

            // calculate snip start and end points
            int snipStart = static_cast<int>( get_rand_int( 1, sz ) );
            int snipEnd = snipStart + snip_maxLen;
            // wrap around
            if ( snipEnd > sz )
                snipEnd -= sz;

            // k=1 makes sure there's at least one trip through the for loop
            for ( int k = 1; k < snip_reps; ++k )
            {
                // stuff al samples between snipBegin and snipEnd
                for ( int ix = snipStart; ix < snipEnd; ++ix )
                {
                    vsnip.push_back( vsamps.at( static_cast<size_t>( ix ) ) );
                    ++count;
                }
            }

            // stuff vsnip into veffect on this trip through the for loop
            std::copy( vsnip.begin(), vsnip.end(), std::back_inserter( veffect ) );

            // clear for next time through the loop
            vsnip.clear();
        }
        // This displays the playback time and gives you a chance to click the Stop button
        MY_TYPE seconds = 1.0 * count / FS;
        label->setNum( seconds );
        qDebug() << "count " << count << " " << veffect.size();
}
