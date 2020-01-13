/***************************************************************
 hw111_boilerplate.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw111
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-01-08
 TIME: 14:33:47
 ***************************************************************/

/* JE =================================
GRADE:	100
COMMENTS:
In future class you'll see
const std::string str_header(54, '*');
======================================*/

#include <iostream>
#include <string>

const std::string str_header{"/***************************************************************"};
const std::string str_footer{"***************************************************************/"};

void write_header()
{
	std::cout << str_header << std::endl;
}

void write_body()
{
	std::cout << "hw111_boilerplate.cpp\nCopyright(c) Carleton College CS312 free open source\nAssignment : hw111\nStritzel Matt stritzelm@carleton.edu\nBrown Cam brownc2@carleton.edu\nDATE : 2020-01-08\nTIME: 14:33:47" << std::endl;
}

void write_footer()
{
	std::cout << str_footer << std::endl;
}

int main()
{
	write_header();
	write_body();
	write_footer();
}
