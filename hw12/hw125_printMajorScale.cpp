/***************************************************************
hw125_printMajorScale.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw125
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

#include <iostream>


/* Write a program to print the notes in MIDIDisplay_DLS format needed to play a major scale on any starting note. */

void print_major_scale( int start_note) {
  
    const char kTAB = '\t';
    int j = 0;
    for(int i = 0; i <= 12;){
        std::cout << j << kTAB << 90 << kTAB << start_note + i << kTAB << 100 << std::endl;
        std::cout << j + 400 << kTAB << 80 << kTAB << start_note + i << kTAB << 0 << std::endl;
        if(i == 4 or i == 11){
            i += 1;
        }
        else{
            i += 2;
        }
        j+= 500;
    }
}

int main() {
  // whatever's needed
  int note = 60; // starting pitch
  print_major_scale( note );
} 
