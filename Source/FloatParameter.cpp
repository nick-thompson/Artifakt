/*
  ==============================================================================

    FloatParameter.cpp
    Created: 26 Oct 2015 1:05:22pm
    Author:  Nick Thompson

  ==============================================================================
*/

#include "FloatParameter.h"

FloatParameter::FloatParameter(float defaultParameterValue, const String& paramName)
    : m_defaultValue(defaultParameterValue),
      m_value(defaultParameterValue),
      m_name(paramName)
{
}

FloatParameter::~FloatParameter()
{
}

float FloatParameter::getValue() const
{
    return m_value;
}

void FloatParameter::setValue (float newValue)
{
    m_value = newValue;
}

float FloatParameter::getDefaultValue() const
{
    return m_defaultValue;
}

String FloatParameter::getName (int /* maximumStringLength */) const
{
    return m_name;
}

String FloatParameter::getLabel() const
{
    return String();
}

float FloatParameter::getValueForText (const String& text) const
{
    return text.getFloatValue();
}