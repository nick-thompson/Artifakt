/*
  ==============================================================================

    ArtifaktVoice.h
    Created: 26 Oct 2015 3:20:25pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"

#ifndef ARTIFAKTVOICE_H_INCLUDED
#define ARTIFAKTVOICE_H_INCLUDED

class ArtifaktVoice  : public SynthesiserVoice
{
public:
    ArtifaktVoice();

    bool canPlaySound (SynthesiserSound* sound) override;

    void setCurrentPlaybackSampleRate (double newRate) override;

    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound* sound,
                    int currentPitchWheelPosition) override;

    void stopNote (float velocity, bool allowTailOff) override;
    void pitchWheelMoved (int newValue) override;

    void controllerMoved (int controllerNumber, int newValue) override;

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample,
                          int numSamples) override;

private:
    double m_index;
    double m_increment;
    double m_level;
};

#endif  // ARTIFAKTVOICE_H_INCLUDED
