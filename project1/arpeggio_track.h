//hw423_CSopranoTrack.h
#ifndef ARPEGGIO_TRACK_H
#define ARPEGGIO_TRACK_H

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

class ArpeggioTrack : public CScalesTrack
{
private:
    std::vector<std::string> info_vector_;
    std::string pat_;
public:
    ArpeggioTrack(uint32_t begintime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
               uint8_t patch, uint8_t volume, uint8_t pan, uint8_t range, std::string pattern, std::vector<std::string> infoVec);
    void write_track() override;
    void write_arpeggio_track();
    std::string get_pattern() const {return pat_;}
    std::vector<std::string> get_infoVec() const {return info_vector_;}
};

const std::vector<std::string> notes_sharps{"CN", "C#", "DN", "D#", "EN", "FN", "F#", "GN", "G#", "AN", "A#", "BN"};
const std::vector<std::string> notes_flats{"CN", "Db", "DN", "Eb", "EN", "FN", "Gb", "GN", "Ab", "AN", "Bb", "BN"};
const std::vector<std::string> modifier_list{"M", "m", "7"};
const std::vector<int> major_chord{0, 4, 7};
const std::vector<int> minor_chord{0, 3, 7};
const std::vector<int> seventh_chord{0, 4, 7, 10};

#endif // ARPEGGIO_TRACK_H_
