/*
  ==============================================================================

    Oscillator.h
    Created: 26 Oct 2015 4:35:00pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"
#include "FloatParameter.h"

#ifndef OSCILLATOR_H_INCLUDED
#define OSCILLATOR_H_INCLUDED

class Oscillator
{
public:
    Oscillator (AudioProcessorParameter* waveformType,
                AudioProcessorParameter* detune,
                AudioProcessorParameter* distortionType,
                AudioProcessorParameter* distortionAmt);
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
    FloatParameter* m_detuneParam;
    
    double m_sampleRate;
    float m_index;
    float m_increment;
    float m_level;
};

#endif  // OSCILLATOR_H_INCLUDED
