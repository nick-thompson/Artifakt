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
const unsigned kMaxNumberOfPartials = Wavetable::size / 2;

const float kCentsPerRange = 1200.0f / kBandsPerOctave;

Wavetable::Wavetable (AudioProcessorParameter* waveformType,
           AudioProcessorParameter* distortionType,
           AudioProcessorParameter* distortionAmt)
{
    m_waveformTypeParam = dynamic_cast<FloatParameter*>(waveformType);
    m_distortionTypeParam = dynamic_cast<FloatParameter*>(distortionType);
    m_distortionAmtParam = dynamic_cast<FloatParameter*>(distortionAmt);

    m_table.resize(kNumRanges * size);

    for (int i = 0; i < kNumRanges; i++)
    {
        unsigned numPartials = numberOfPartialsForRange(i);
        for (int j = 0; j < size; j++)
        {
            for (int k = 1; k <= numPartials; k++)
            {
                double t = (double) j / size;
                double sample = std::sin(2.0 * double_Pi * (double) k * t)
                    / ((double) k * double_Pi);

                m_table[i * size + j] += (float) sample;
            }
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

unsigned Wavetable::numberOfPartialsForRange(unsigned range) const
{
   // Number of cents below nyquist where we cull partials.
    float centsToCull = range * kCentsPerRange;

    // A value from 0 -> 1 representing what fraction of the partials to keep.
    float cullingScale = pow(2, -centsToCull / 1200);

    // The very top range will have all the partials culled.
    unsigned numberOfPartials = cullingScale * kMaxNumberOfPartials;

    return numberOfPartials;
}
