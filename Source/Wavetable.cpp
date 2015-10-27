/*
  ==============================================================================

    Wavetable.cpp
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Wavetable.h"

const unsigned Wavetable::size = 1024;

const unsigned kBandsPerOctave = 3;
const unsigned kNumRanges = 0.5 * kBandsPerOctave * log2f(Wavetable::size);

const float kCentsPerRange = 1200.0f / kBandsPerOctave;

Wavetable::Wavetable (AudioProcessorParameter* waveformType,
           AudioProcessorParameter* distortionType,
           AudioProcessorParameter* distortionAmt)
{
    m_waveformTypeParam = dynamic_cast<FloatParameter*>(waveformType);
    m_distortionTypeParam = dynamic_cast<FloatParameter*>(distortionType);
    m_distortionAmtParam = dynamic_cast<FloatParameter*>(distortionAmt);

    m_table.resize(kNumRanges * size);
    for (unsigned int i = 0; i < kNumRanges; i++)
    {
        for (unsigned int j = 0; j < size; j++)
        {
            // TODO: Construct band-limited tables via additive synthesis. Will
            // need to account for 4 wave types...
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            m_table[i * size + j] = r;
        }
    }
}

Wavetable::~Wavetable ()
{
}

void Wavetable::setSampleRate(double sampleRate)
{
    m_sampleRate = sampleRate;
}

float Wavetable::get(unsigned range, unsigned index) const
{
    // TODO: Here we'll interpolate using waveformType, then apply the transfer
    // function from the distortion parameters.
    return m_table[range * size + index];
}

unsigned Wavetable::pitchRangeForFrequency(double freq) const
{
    // TODO
    return 0;
}
