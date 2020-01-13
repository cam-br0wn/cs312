// helloMidi.cpp
#include <iostream>
#include <string>

const char kTAB = '\t';
// write_comment()
// prints lines that start with # followed by string s
// string s does not contain the "# " (pound space) to start the line
void write_comment(const std::string &s) {
  std::cout << "# " << &s << std::endl;
}

// write_midi_message_nodata2(...)
// 0xC0 status bytes are followed by one data byte
// prints lines that begin with numbers
void write_midi_message_nodata2(int32_t time_stamp, int16_t status,
                                int16_t data1) 
{
  std::cout << time_stamp << kTAB << status << kTAB << data1 << std::endl;
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
  write_comment("A MIDI message contains three or four numbers separated by a single tab character");
  write_comment("number 1 is a time stamp in milliseconds in decimal format");
  write_comment("number 2 is a MIDI status message in hexadecimal format without the 0x prefix (range 0x80 - 0xFF)");
  write_comment("number 3 is a MIDI data1 message in decimal format (range 0 - 127)");
  write_comment("number 4 is a MIDI data2 message in decimal format (range 0 - 127)");
  std::cout << "\n" << std::endl;
  write_comment("status 0xC0 begins a a patch change message");
  write_comment("indicating which instrument sound to use");
  write_comment("patch change messages do not use data2");
  write_comment("data1 is the instrument number.");
  write_midi_message_nodata2(0, 0xc0, 0);

//  std::cout << "\nIf midi message status is 0xC0 use" << std::endl;
//  write_midi_message_nodata2(0, 0, 0);
//
//  std::cout << "\nElse if midi message status is 0x80 or 0x90 use" << std::endl;
//  write_midi_message_hasdata2(0, 0, 0, 0);
}