/*
  ==============================================================================

    Oscillator.cpp
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Oscillator.h"

using wavetable::WaveType;

//==============================================================================
/**
 * Utility function for performing a linear interpolation between two values.
*/
inline float lerpf(float a, float b, float alpha)
{
    return (1.0f - alpha) * a + alpha * b;
}

//==============================================================================
Oscillator::Oscillator (AudioParameterInt* detune,
                        AudioParameterFloat* waveType)
{
    m_detuneParam = detune;
    m_waveTypeParam = waveType;
}

Oscillator::~Oscillator ()
{
}

void Oscillator::setSampleRate(double sampleRate)
{
    m_sampleRate = sampleRate;
}

void Oscillator::noteOn (int midiNoteNumber, float velocity)
{
    m_index = 0.0;
    m_level = velocity * 0.15;

    int detune = *m_detuneParam;

    double ratio = pow(2, (double) detune / 1200.0);
    double cyclesPerSecond =
        MidiMessage::getMidiNoteInHertz(midiNoteNumber) * ratio;
    double cyclesPerSample = cyclesPerSecond / m_sampleRate;

    float waveTypeValue = *m_waveTypeParam;
    unsigned lTypeIndex = static_cast<unsigned>(waveTypeValue);
    unsigned rTypeIndex = (lTypeIndex == wavetable::NUM_WAVE_TYPES - 1)
        ? lTypeIndex : lTypeIndex + 1;

    m_left = wavetable::getTable(lTypeIndex, cyclesPerSecond);
    m_right = wavetable::getTable(rTypeIndex, cyclesPerSecond);
    m_tableAlpha = waveTypeValue - (float) lTypeIndex;
    m_increment = cyclesPerSample * wavetable::kTableSize;
}

void Oscillator::noteOff (float velocity, bool allowTailOff)
{
    // TODO: Getting clicks on noteOff because the sample abruptly stops instead
    // of quickly fading off.
    m_increment = 0.0;
}

void Oscillator::render (AudioSampleBuffer& outputBuffer,
                         int startSample,
                         int numSamples)
{
    if (m_increment != 0.0) {
        unsigned readIndexMask = wavetable::kTableSize - 1;

        while (--numSamples >= 0) {
            unsigned readIndex = static_cast<unsigned>(m_index);
            unsigned readIndexWrappedLeft = readIndex & readIndexMask;
            unsigned readIndexWrappedRight = (readIndex + 1) & readIndexMask;

            float left = lerpf(
                m_left[readIndexWrappedLeft],
                m_left[readIndexWrappedRight],
                (float) m_index - (float) readIndex
            );

            float right = lerpf(
                m_right[readIndexWrappedLeft],
                m_right[readIndexWrappedRight],
                (float) m_index - (float) readIndex
            );

            float sample = lerpf(left, right, m_tableAlpha) * m_level;

            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample(i, startSample, sample);

            ++startSample;
            m_index += m_increment;

            if (m_index > wavetable::kTableSizef)
            {
                // New wavetable cycle. Update wave tables for pitch slides.
                // m_freq *= slideFactor;
                // m_table = wavetable::getTable(wavetable::SAW, freq);
                m_index -= wavetable::kTableSizef;
            }
        }
    }
}
