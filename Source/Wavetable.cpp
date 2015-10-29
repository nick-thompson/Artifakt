/*
  ==============================================================================

    Wavetable.cpp
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Wavetable.h"

namespace wavetable
{

    std::vector<float> data(NUM_WAVE_TYPES * kNumRanges * kTableSize);
    std::vector<int> lookup(NUM_WAVE_TYPES * kNumRanges);

    void init()
    {
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

            // Normalize the wavetable
            float max = 0.0f;
            for (int jj = 0; jj < kTableSize; jj++)
            {
                float sample = fabs(data[wavetableIndex + jj]);
                if (sample > max)
                    max = sample;
            }

            for (int jj = 0; jj < kTableSize; jj++)
                data[wavetableIndex + jj] /= max;

            // Set the lookup entry.
            lookup[SAW * kNumRanges + ii] = wavetableIndex;
        }
    }

    float* getTable(WaveType t, double fq)
    {
        // Enforce that `init` has already been called.
        jassert(!data.empty());

        // Determine the closest appropriate MIDI note value.
        int note = 69 + (int) ceil(12.0 * log2(fq / 440.0));
        DBG(note);

        // Offset the return pointer from the front of the array.
        return data.data() + lookup[t * kNumRanges + note];
    }
}
