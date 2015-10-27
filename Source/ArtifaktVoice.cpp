/*
  ==============================================================================

    ArtifaktVoice.cpp
    Created: 26 Oct 2015 3:20:25pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "ArtifaktVoice.h"
#include "ArtifaktSound.h"

ArtifaktVoice::ArtifaktVoice(Oscillator* top, Oscillator* bottom)
    : m_top(top),
      m_bottom(bottom),
      m_index(0.0),
      m_increment(0.0)
{
}

bool ArtifaktVoice::canPlaySound(SynthesiserSound* sound) {
    return dynamic_cast<ArtifaktSound*> (sound) != nullptr;
}

void ArtifaktVoice::setCurrentPlaybackSampleRate(double newRate) {
    SynthesiserVoice::setCurrentPlaybackSampleRate(newRate);
    m_top->setSampleRate(newRate);
    m_bottom->setSampleRate(newRate);
}

void ArtifaktVoice::pitchWheelMoved(int /*newValue*/) {
    // Not gonna do anything here for now...
}

void ArtifaktVoice::controllerMoved(int /*controllerNumber*/, int /*newValue*/) {
    // Not gonna do anything here for now...
}

void ArtifaktVoice::startNote(int midiNoteNumber, float velocity,
                         SynthesiserSound* /*sound*/,
                         int /*currentPitchWheelPosition*/)
{
    m_top->noteOn(midiNoteNumber, velocity);
    m_bottom->noteOn(midiNoteNumber, velocity);
}

void ArtifaktVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();
    m_top->noteOff(velocity, allowTailOff);
    m_bottom->noteOff(velocity, allowTailOff);
}

void ArtifaktVoice::renderNextBlock(AudioSampleBuffer& outputBuffer,
                               int startSample, int numSamples)
{
    m_top->render(outputBuffer, startSample, numSamples);
    m_bottom->render(outputBuffer, startSample, numSamples);
}
