#include <iostream>
#include <string>
#include <fstream>
#include <regex>

#ifndef HW312_CMIDIPACKET_H_
#include "hw312_CMidiPacket.h"
#endif

using namespace CMP31;

//From TCPP2 9.4.1 page 116
void line_to_midipacket(std::string line)
{
	// use a Raw string
	std::regex pat(R"(^(\S+)\s+(\S+)\s+(\S+)\s*(\S*))");
	std::smatch matches;
	if (std::regex_search(line, matches, pat))
	{
		CMidiPacket mp(matches[0]);
		mp.print();
		//
		std::cout << "# "
							<< matches[1] << '\t'
							<< matches[2] << '\t'
							<< matches[3] << '\t'
							<< matches[4] << std::endl;
	}
}

int main()
{
	std::string fname = "../c313_helloMidi.txt";
	std::ifstream ifs;
	ifs.open(fname);
	if (!ifs.is_open())
	{
		std::cout << fname << " could not be opened" << std::endl;
		exit(0);
	}

	std::string line;
	while (getline(ifs, line))
		line_to_midipacket(line);
}