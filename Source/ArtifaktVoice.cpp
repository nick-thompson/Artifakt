/*
  ==============================================================================

    ArtifaktVoice.cpp
    Created: 26 Oct 2015 3:20:25pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "ArtifaktVoice.h"
#include "ArtifaktSound.h"

ArtifaktVoice::ArtifaktVoice()
    : m_index(0.0),
      m_increment(0.0)
{
}

bool ArtifaktVoice::canPlaySound(SynthesiserSound* sound) {
    return dynamic_cast<ArtifaktSound*> (sound) != nullptr;
}

void ArtifaktVoice::setCurrentPlaybackSampleRate(double newRate) {
    SynthesiserVoice::setCurrentPlaybackSampleRate(newRate);
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
    m_index = 0.0;
    m_level = velocity * 0.15;

    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();

    m_increment = cyclesPerSample * 4096.0;
}

void ArtifaktVoice::stopNote(float /*velocity*/, bool /*allowTailOff*/)
{
    clearCurrentNote();
    m_increment = 0.0;
}

void ArtifaktVoice::renderNextBlock(AudioSampleBuffer& outputBuffer,
                               int startSample, int numSamples)
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
