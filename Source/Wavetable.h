/*
  ==============================================================================

    Wavetable.h
    Created: 27 Oct 2015 11:12:15am
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"
#include "FloatParameter.h"

#ifndef WAVETABLE_H_INCLUDED
#define WAVETABLE_H_INCLUDED

class Wavetable
{
public:
    Wavetable (AudioProcessorParameter* waveformType,
               AudioProcessorParameter* distortionType,
               AudioProcessorParameter* distortionAmt);

    ~Wavetable ();

    void setSampleRate (double sampleRate);

    float get (unsigned range, unsigned index) const;

    unsigned pitchRangeForFrequency (double freq) const;
    unsigned numberOfPartialsForRange (unsigned range) const;

    static const unsigned size;

private:
    FloatParameter* m_waveformTypeParam;
    FloatParameter* m_distortionTypeParam;
    FloatParameter* m_distortionAmtParam;

    double m_sampleRate;

    std::vector<float> m_table;
};



#endif  // WAVETABLE_H_INCLUDED
