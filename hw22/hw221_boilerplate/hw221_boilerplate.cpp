#include <iostream>
#include <string>

const std::string str_header{"/***************************************************************"};
const std::string str_footer{"***************************************************************/"};

void write_header()
{
	std::cout << str_header << std::endl;
}

void write_body(const std::string &assignment_name, const std::string &file_name)
{
	std::string file = file_name;
	std::string assignment = assignment_name;
	
	std::cout << file << "\nCopyright(c) Carleton College CS312 free open source\nAssignment : " << assignment_name << " \nStritzel Matt stritzelm@carleton.edu\nBrown Cam brownc2@carleton.edu\nDATE : 2020-01-08\nTIME: 14:33:47" << std::endl;
}

void write_footer()
{
	std::cout << str_footer << std::endl;
}

int main(int argc, char *argv[])
{

	// size_t size = sizeof(argv) / sizeof(argv[0]);  ****Handle usage error by checking length of argv
	write_header();
	write_body(argv[1], argv[2]);
	write_footer();
}