/*
  ==============================================================================

    Wavetable.h
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"

#ifndef WAVETABLE_H_INCLUDED
#define WAVETABLE_H_INCLUDED

namespace wavetable
{
    // Number of samples in a given wavetable.
    const unsigned kTableSize = 4096;

    // Maximum number of partials we can hold in a given wavetable.
    const unsigned kMaxNumberOfPartials = kTableSize / 2;

    // One wavetable for each of 128 frequency ranges, corresponding to those
    // of MIDI note values.
    const unsigned kNumRanges = 128;

    // Four possible wave types, in an order representing how they morph
    // into one another.
    enum WaveType { SINE, TRIANGLE, SAW, SQUARE, NUM_WAVE_TYPES };

    // Container for the wavetable data. Each WaveType will reserve
    // kNumRanges * kTableSize entries – one band-limited table for each
    // MIDI note value.
    std::vector<float> data;

    // A separate vector mapping MIDI note values to wavetable indeces.
    std::vector<int> lookup(NUM_WAVE_TYPES * kNumRanges);

    // Responsible for initializing the data vector.
    void init();

    // Returns a pointer into the data container, pointing at the first
    // entry of the appropriate table given WaveType and the corresponding
    // frequency value.
    float* getTable(WaveType t, double fq);
}

#endif  // WAVETABLE_H_INCLUDED
