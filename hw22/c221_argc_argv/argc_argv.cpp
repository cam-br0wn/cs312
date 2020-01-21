// argc_argv.cpp
#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "argc\t\t" << argc << std::endl;
	for (int ix = 0; ix < argc; ++ix)
		std::cout << "argv[" << ix << "]\t" << argv[ix] << std::endl;
	return 0;
}