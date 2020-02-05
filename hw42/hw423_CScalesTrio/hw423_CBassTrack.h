// hw423_CBassTrack.h
#ifndef HW423_CBASSTRACK_H
#define HW423_CBASSTRACK_H

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

class CBassTrack : public CScalesTrack
{
public:
    CBassTrack(uint32_t begintime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
               uint8_t patch, uint8_t volume, uint8_t pan);
    void write_track() override;
};
#endif // CBASSTRACK_H