// boilerplate here

#include <iostream>
// add more includes as needed

void print_header()
{
  std::cout << "Match Header line by line from web page.\n";
  std::cout << std::endl;
}

int main()
{
  // Use either full pathname or relative pathname to the working directory
  const std::string file_name = "xxx";

  // Open the drumNotes.txt file

  // Report error if file could not be opened
  if (!file.is_open())
  {
    std::cout << file_name << " could not be opened" << std::endl;
    return 0;
  }

  print_header();

  // use std::getline to read file line by line
  // display each line using std::cout

  return 0;
}