/*
  ==============================================================================

    Oscillator.cpp
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Oscillator.h"

using wavetable::WaveType;

Oscillator::Oscillator (AudioProcessorParameter* detune,
                        AudioProcessorParameter* waveType)
{
    m_detuneParam = dynamic_cast<FloatParameter*>(detune);
    m_waveTypeParam = dynamic_cast<FloatParameter*>(waveType);
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

    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / m_sampleRate;

    unsigned waveType = static_cast<unsigned>(m_waveTypeParam->getValue());
    WaveType type = static_cast<WaveType>(waveType);

    m_table = wavetable::getTable(type, cyclesPerSecond);
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

            float leftSample = m_table[readIndexWrappedLeft];
            float rightSample = m_table[readIndexWrappedRight];

            // Linear interpolation
            const float alpha = (float) m_index - (float) readIndex;
            const float invAlpha = 1.0f - alpha;
            const float sample =
                ((invAlpha * leftSample) + (alpha * rightSample)) * m_level;

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
