/*
  ==============================================================================

    Oscillator.cpp
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "Oscillator.h"

Oscillator::Oscillator (AudioProcessorParameter* waveformType,
                        AudioProcessorParameter* detune,
                        AudioProcessorParameter* distortionType,
                        AudioProcessorParameter* distortionAmt)
{
    m_detuneParam = dynamic_cast<FloatParameter*>(detune);
}

Oscillator::~Oscillator ()
{
}

void Oscillator::setSampleRate(double sampleRate) {
    m_sampleRate = sampleRate;
}

void Oscillator::noteOn (int midiNoteNumber, float velocity)
{
    m_index = 0.0;
    m_level = velocity * 0.15;
    
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / m_sampleRate;
    
    m_increment = cyclesPerSample * 4096.0;
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
        while (--numSamples >= 0) {
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float currentSample = r * m_level;
            for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample(i, startSample, currentSample);
            
            ++startSample;
        }
    }
}