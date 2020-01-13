/***************************************************************
hw124_asciTool.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw124
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2019-1-09
TIME: 14:46:25
****************************************************************/

#include <iostream>

int main() {

  /*   Then modify it to produce the ASCII chart shown below. */
    for (int c = 0; c <= 127; ++c) {
        std::cout << static_cast<int>(c) << " = " << static_cast<char>(c) << std::endl;
    }
}
