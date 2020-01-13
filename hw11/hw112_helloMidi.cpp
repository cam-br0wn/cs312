// helloMidi.cpp
#include <iostream>
#include <string>

// write_comment()
// prints lines that start with # followed by string s
// string s does not contain the "# " (pound space) to start the line
void write_comment(const std::string &s) {
  std::cout << "  write_comment()\t\t// you write" << std::endl;
}

// write_midi_message_nodata2(...)
// 0xC0 status bytes are followed by one data byte
// prints lines that begin with numbers
void write_midi_message_nodata2(int32_t time_stamp, int16_t status,
                                int16_t data1) 
{
  std::cout << "  write_midi_message_nodata2()\t// you write" << std::endl;
}

// write_midi_message_hasdata2(...)
// 0x80 and 0x90 status bytes are followed by two data bytes
// use  hasData2() to insure that the 0xC0 does not output data2
void write_midi_message_hasdata2(unsigned int timeStamp, unsigned char status,
                                 unsigned char data1, unsigned char data2) 
{
  std::cout << "  write_midi_message_hasdata2()\t// you write" << std::endl;
}

// write formatted output exactly as shown below
// use the three functions you implemented above
int main() {
  std::cout << "If line begins with # use" << std::endl;
  write_comment(" ");

  std::cout << "\nIf midi message status is 0xC0 use" << std::endl;
  write_midi_message_nodata2(0, 0, 0);

  std::cout << "\nElse if midi message status is 0x80 or 0x90 use" << std::endl;
  write_midi_message_hasdata2(0, 0, 0, 0);
}