/*
  ==============================================================================

    Oscillator.h
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"
#include "Wavetable.h"

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

class Oscillator
{
public:
    Oscillator (AudioParameterInt* detune,
                AudioParameterFloat* waveType);
    ~Oscillator ();

    void setSampleRate (double sampleRate);

    // Called in the parent voice's startNote method.
    void noteOn (int midiNoteNumber, float velocity);

    // Called in the parent voice's stopNote method.
    void noteOff (float velocity, bool allowTailOff);

    // Responsible for rendering the next audio block.
    void render (AudioSampleBuffer& outputBuffer,
                 int startSample,
                 int numSamples);

private:
    AudioParameterInt* m_detuneParam;
    AudioParameterFloat* m_waveTypeParam;

    double m_sampleRate;

    // Each oscillator draws from two wavetables as determined by the waveType
    // parameter.
    float* m_left;
    float* m_right;

    float m_index;
    float m_increment;
    float m_level;
    float m_tableAlpha;
};

#endif  // OSCILLATOR_H_INCLUDED
