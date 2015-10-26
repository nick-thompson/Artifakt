/*
  ==============================================================================

    FloatParameter.h
    Created: 26 Oct 2015 1:05:22pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "JuceHeader.h"

#ifndef FLOATPARAMETER_H_INCLUDED
#define FLOATPARAMETER_H_INCLUDED

class FloatParameter : public AudioProcessorParameter
{
public:
    FloatParameter (float defaultParameterValue, const String& paramName);
    ~FloatParameter ();

    float getValue() const override;
    void setValue (float newValue) override;

    float getDefaultValue() const override;

    String getName (int /* maximumStringLength */) const override;
    String getLabel() const override;

    float getValueForText (const String& text) const override;

private:
    float m_defaultValue;
    float m_value;
    String m_name;
};

#endif  // FLOATPARAMETER_H_INCLUDED
