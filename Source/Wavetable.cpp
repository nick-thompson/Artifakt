/*
  ==============================================================================

    Wavetable.cpp
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Wavetable.h"

using namespace wavetable;

void wavetable::init()
{
    // Appropriate enough space in the vector.
    data.resize(NUM_WAVE_TYPES * kNumRanges * kTableSize);

    for (int ii = 0; ii < kNumRanges; ii++)
    {
        // Assuming a sample rate of 44100...
        double fq = MidiMessage::getMidiNoteInHertz(ii);
        unsigned numPartials = (int) (44100.0f * 0.5f / fq);
        unsigned wavetableIndex = SAW * ii * kTableSize;

        // Fill the current wavetable
        for (int jj = 0; jj < kTableSize; jj++)
        {
            for (int kk = 1; kk <= numPartials; kk++)
            {
                double t = (double) jj / kTableSize;
                double sample = std::sin(2.0 * double_Pi * (double) kk * t)
                    / ((double) kk * double_Pi);

                data[wavetableIndex + jj] += (float) sample;
            }
        }

        // Set the lookup entry.
        lookup[SAW * kNumRanges + ii] = wavetableIndex;
    }
}

float* wavetable::getTable(WaveType t, double fq)
{
    // Enforce that `init` has already been called.
    jassert(!data.empty());

    // Determine the closest appropriate MIDI note value.
    int noteValue = 69 + (int) ceil(12.0 * log2(fq / 440.0));
    int lookupIndex = t * kNumRanges + noteValue;

    float* p = data.data() + lookupIndex * sizeof(float);
    return p;
}
