/*
  ==============================================================================

    Wavetable.cpp
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Wavetable.h"

namespace Wavetable
{

    std::vector<float> data;

    void init()
    {
        int rawSize;
        int numSamples;

        const char* p = BinaryData::getNamedResource("wavetable_data", rawSize);

        numSamples = rawSize / sizeof(int32_t);
        data.resize(numSamples);

        const int32_t* samples = reinterpret_cast<const int32_t*>(p);
        for (int i = 0; i < numSamples; i++)
            data[i] = ((float) samples[i]) / 2147483647.0f;
    }

    float* getTable(WaveType t, double fq)
    {
        // Enforce that `init` has already been called.
        jassert(!data.empty());

        // Determine the closest appropriate MIDI note value.
        int note = 69 + (int) ceil(12.0 * log2(fq / 440.0));
        int offset = (t * kNumRanges * kTableSize) + (kTableSize * note);

        // Offset the return pointer from the front of the array.
        return data.data() + offset;
    }

    float* getTable(int typeIndex, double fq)
    {
        WaveType t = static_cast<WaveType>(typeIndex);
        return getTable(t, fq);
    }
}
