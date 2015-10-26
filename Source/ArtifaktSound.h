/*
  ==============================================================================

    ArtifaktSound.h
    Created: 26 Oct 2015 3:19:12pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"

#ifndef ARTIFAKTSOUND_H_INCLUDED
#define ARTIFAKTSOUND_H_INCLUDED

class ArtifaktSound : public SynthesiserSound
{
public:
    ArtifaktSound() {};

    bool appliesToNote (int /* midiNoteNumber */) override { return true; };
    bool appliesToChannel (int /* midiChannel */) override { return true; };
};

#endif  // ARTIFAKTSOUND_H_INCLUDED
