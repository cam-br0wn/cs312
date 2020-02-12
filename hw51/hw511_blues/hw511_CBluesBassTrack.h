// hw511_CBluesBassTrack.h
#ifndef HW511_CBLUESBASSTRACK_H_
#define HW511_CBLUESBASSTRACK_H_

#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

// DO NOT MODIFY

class CBluesBassTrack : public CInstrument
{
public:
  // constructor
  CBluesBassTrack(uint32_t beginTm, uint32_t endTm, int scaleOffset, int chan,
                  int patch, int vol, int pan, int startNote, int meas);

  // This is the only function needed
  void write_one_measure(int meas, int chan) override;
};
#endif // HW511_CBLUESBASSTRACK_H_