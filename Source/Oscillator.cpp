/*
  ==============================================================================

    Oscillator.cpp
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Oscillator.h"

Oscillator::Oscillator (Wavetable* wt, AudioProcessorParameter* detune)
    : m_wavetable(wt)
{
    m_detuneParam = dynamic_cast<FloatParameter*>(detune);
}

Oscillator::~Oscillator ()
{
}

void Oscillator::setSampleRate(double sampleRate) {
    m_sampleRate = sampleRate;
    m_wavetable->setSampleRate(sampleRate);
}

void Oscillator::noteOn (int midiNoteNumber, float velocity)
{
    m_index = 0.0;
    m_level = velocity * 0.15;

    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / m_sampleRate;

    m_increment = cyclesPerSample * Wavetable::size;
}

void Oscillator::noteOff (float velocity, bool allowTailOff)
{
    m_increment = 0.0;
}

void Oscillator::render (AudioSampleBuffer& outputBuffer,
                         int startSample,
                         int numSamples)
{
    if (m_increment > 0.0) {
        unsigned mask = Wavetable::size - 1;
        while (--numSamples >= 0) {
            unsigned readIndex = static_cast<unsigned>(m_index);

            float currentSample = m_wavetable->get(0, readIndex & mask) * m_level;
            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample(i, startSample, currentSample);

            ++startSample;
            m_index += m_increment;
        }
    }
}
