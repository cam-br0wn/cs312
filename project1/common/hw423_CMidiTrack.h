// hw423_CMidiTrack.h
#ifndef HW423_CMIDITRACK_H_
#define HW423_CMIDITRACK_H_

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <vector>

// DO NOT MODIFY THIS CODE

using namespace CMP33;

class CMidiTrack
{
private: // not really needed they'd be private by default
  uint32_t beginTimestamp_;
  uint32_t endTimestamp_;
  uint8_t noteOffset_;
  uint8_t channel_;
  uint8_t patch_;
  uint8_t volume_;
  uint8_t pan_;
  uint8_t expr_;

public:
  std::vector<CMidiPacket> vtrk;

  // the big six - all default - not declared

  // only constructor
  // Note use of default parameter for expr
  // A default paramter does not need to be included when the constructor is called
  // unless you want to change it to a default value
  // You can have more than one default parameter but they must appear at then end
  CMidiTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
             uint8_t patch, uint8_t volume, uint8_t pan, uint8_t expr = 100);

  // Getters
  // These simple functions are all declared and defined inline
  // They do not appear in the .cpp file
  // You should only do this for simple functions.
  // Inline header files may not show up in the debugger
  uint32_t get_beginTimestamp() const { return beginTimestamp_; };
  uint32_t get_endTimestamp() const { return endTimestamp_; };
  uint8_t get_noteOffset() const { return noteOffset_; };
  uint8_t get_channel() const { return channel_; };
  uint8_t get_patch() const { return patch_; };
  uint8_t get_volume() const { return volume_; };
  uint8_t get_pan() const { return pan_; };
  uint8_t get_expression() const { return expr_; };

  // Setters - also declared and defined inline
  void set_beginTimestamp(const uint32_t &ts) { beginTimestamp_ = ts; };
  void set_endTimestamp(const uint32_t &ts) { endTimestamp_ = ts; };
  void set_noteOffset(const uint8_t &ofst) { noteOffset_ = ofst; };
  void set_channel(const uint8_t &chan) { channel_ = chan; };
  void set_patch(const uint8_t &patch) { patch_ = patch; };
  void set_volume(const uint8_t &vol) { volume_ = vol; };
  void set_pan(const uint8_t &pan) { pan_ = pan; };
  void set_expression(const uint8_t &expr) { expr_ = expr; };

  // Send these Midi Message
  // These will appear in the .cpp file and you'll need to implement them
  // For now send means write to std::cout
  void push_non(uint32_t tm, uint8_t chan, uint8_t note, uint8_t vel);
  void push_nof(uint32_t tm, uint8_t chan, uint8_t note);
  void push_patch(uint32_t tm, uint8_t chan, uint8_t patch);
  void push_volume(uint32_t tm, uint8_t chan, uint8_t vol);
  void push_pan(uint32_t tm, uint8_t chan, uint8_t pan);
  void push_expression(uint32_t tm, uint8_t chan, uint8_t expr);

  // Example of a pure virtual function
  // This is now an abstract bass class and cannot be created in other files
  // That means you'll have to write subclasses that inherit from CMidiTrack
  // Subclasses are required to declare an implement the write_track() function
  // Subclasses get all the functions found in CMidiTrack for free.
  virtual void write_track() = 0;
};

#endif // HW423_CMIDITRACK_H_
