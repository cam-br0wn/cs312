// boilerplate here

#include <iostream>
// add more includes as needed

void print_header()
{
  std::cout << "Match Header line by line from web page.\n";
  std::cout << std::endl;
}

int main() {
  print_header();
  for (auto itr : kVEC_DRUM_NAMES)
    std::cout << itr << std::endl;
}
