// str05_append.cpp

#include <iostream>
#include <string>

int main()
{
    std::string str = "CS 312 Winter 2020";
    // append
    str.append("\n  classroom: WCC138");
    // +
    str = str + "\n  instructor: John Ellinger\n  office: Laird 15";
    // +=
    str += "\n  email: jellinge@carleton.edu\n";
    std::cout << str << std::endl;
}
