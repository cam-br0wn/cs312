# include <stdio.h>
# include <iostream>
# include <sstream>

int main() {
    int n = 0x90;
    
        std::ostringstream oss;
        oss << std::hex << n;
        std::cout << oss.str() << std::endl;
        
        oss.str("");
        oss << std::showbase << std::hex << n;
        std::cout << oss.str() << std::endl;

    
}

/*
The purpose of the extra curly braces is limit the scope of the two separate oss variables so that the compiler knows that they reference different things.
*/