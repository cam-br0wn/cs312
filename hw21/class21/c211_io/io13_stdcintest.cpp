// io13_stdcintest.cpp

#include <iostream>
#include <string>
#include <vector>

int main()
{
	int tmp{0};
	std::vector<int> v;

	std::cout << "Enter lines with four numbers separated by whitespace\n";
	std::cout << "Type Return followed by Control-D when finished.\n";
	while (std::cin >> tmp)
	{
		v.push_back(tmp);
	}
	std::cout << std::endl;

	std::cout << "You entered \n";
	int count{1};
	for (auto n : v)
	{
		std::cout << n << '\t';
		if (count % 4 == 0)
			std::cout << std::endl;
		++count;
	}
}
