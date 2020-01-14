// helloMidi.cpp
#include <iostream>
#include <string>

const char kTAB = '\t';
// write_comment()
// prints lines that start with # followed by string s
// string s does not contain the "# " (pound space) to start the line
void write_comment(const std::string &s) {
  std::cout << "# " << s << std::endl;
}

// write_midi_message_nodata2(...)
// 0xC0 status bytes are followed by one data byte
// prints lines that begin with numberss
void write_midi_message_nodata2(int time_stamp, int status,
                                int data1) 
{
  std::cout << std::dec << time_stamp << kTAB << std::hex << status << kTAB << std::dec << data1 << std::endl;
}

// write_midi_message_hasdata2(...)
// 0x80 and 0x90 status bytes are followed by two data bytes
// use  hasData2() to insure that the 0xC0 does not output data2
void write_midi_message_hasdata2(int time_stamp, int status,
                                 int data1, int data2) 
{
  std::cout << std::dec << time_stamp << kTAB << std::hex << status << kTAB << std:: dec << data1 << kTAB << std::dec << data2 << std::endl;
}

// write formatted output exactly as shown below
// use the three functions you implemented above
int main() {
  write_comment("A MIDI message contains three or four numbers separated by a single tab character");
  write_comment("number 1 is a time stamp in milliseconds in decimal format");
  write_comment("number 2 is a MIDI status message in hexadecimal format without the 0x prefix (range 0x80 - 0xFF)");
  write_comment("number 3 is a MIDI data1 message in decimal format (range 0 - 127)");
  write_comment("number 4 is a MIDI data2 message in decimal format (range 0 - 127)");
  std::cout << std::endl;
  write_comment("status 0xC0 begins a a patch change message");
  write_comment("indicating which instrument sound to use");
  write_comment("patch change messages do not use data2");
  write_comment("data1 is the instrument number.");
  write_midi_message_nodata2(0, 0xc0, 0);
  std::cout << std::endl;
  write_comment("status 0x90 begins a Note On (NON) message");
  write_comment("NON messages use both data1 and data2");
  write_comment("data1 is the MIDI note number that corresponds to");
  write_comment("keys on a piano where Middle C is note number 60");
  write_comment("data2 is the velocity or how loud or soft the note sounds");
  write_midi_message_hasdata2(0, 0x90, 60, 110);
  std::cout << std::endl;
  write_comment("status code 0x80 begins a Note Off (NOF) message");
  write_comment("NOF messages use both data1 and data2");
  write_comment("data1 is the MIDI note number that corresponds to");
  write_comment("keys on a piano where Middle C is note number 60");
  write_comment("data2 should be set to zero");
  write_midi_message_hasdata2(900, 0x80, 60, 0);
  std::cout << std::endl;
  write_comment("Every NON must be followed by a NOF with a later time stamp");
  write_midi_message_hasdata2(1000,0x90,55,80);
  write_midi_message_hasdata2(1400,0x80,55,0);
  write_comment("You can also send a NOF using a NON with a velocity of 0");
  write_midi_message_hasdata2(1500,0x90,55,60);
  write_midi_message_hasdata2(1900,0x90,55,0);
  std::cout << std::endl;
  write_comment("More NON-NOF pairs");
  write_midi_message_hasdata2(2000,0x90,56,100);
  write_midi_message_hasdata2(2900,0x80,56,0);
  write_midi_message_hasdata2(3000,0x90,55,80);
  write_midi_message_hasdata2(4200,0x80,55,0);
  std::cout << std::endl;
  write_comment("Another patch change");
  write_midi_message_nodata2(4999,0xc0,56);
  std::cout << std::endl;
  write_comment("More NON-NOF pairs");
  write_midi_message_hasdata2(5000,0x90,59,110);
  write_midi_message_hasdata2(5900,0x80,59,0);
  write_midi_message_hasdata2(6000,0x90,60,127);
  write_midi_message_hasdata2(8000,0x80,60,0);

}