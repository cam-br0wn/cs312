// boilerplate here

#include <iostream>
// add more includes as needed

void print_header()
{
  std::cout << "Match Header line by line from web page.\n";
  std::cout << std::endl;
  std::cout << "======================================================\n";
  std::cout << "General MIDI drum kit note assignments on channel 10\n";
  std::cout << "Use status 0x99 for NON\n"
  std::cout << "Use status 0x99 and velocity of 0 for NOF\n"
  std::cout << "======================================================\n"
}

int main() {
  print_header();
  for (auto itr : kVEC_DRUM_NAMES)
    std::cout << itr << std::endl;
}
