/***************************************************************
hw124_asciTool.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw124
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

****************************************************************/

// hw124
/* JE =================================
GRADE:	100
COMMENTS:
I peeked into your courses StuWork/<email_name>/bin folder and I found
/Volumes/COURSES/cs312-00-w20/StuWork/brownc/bin
    nothing
/Volumes/COURSES/cs312-00-w20/StuWork/stritzelm/bin
├── ascii
└── ascii.dSYM <== delete this
You should both have had ascii in your bin folder. It's a useful tool
Next time directions say to copy a file to your bin folder both do it.
2 points off next time for person whose missing it.
======================================*/

#include <iostream>

int main() {

  /*   Then modify it to produce the ASCII chart shown below. */
    for (int c = 0; c <= 127; ++c) {
        std::cout << static_cast<int>(c) << " = " << static_cast<char>(c) << std::endl;
    }
}
