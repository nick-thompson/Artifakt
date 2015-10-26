/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "OscillatorEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscillatorEditor::OscillatorEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_waveformTypeSlider = new Slider ("Waveform Type Slider"));
    m_waveformTypeSlider->setRange (0, 10, 0);
    m_waveformTypeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_waveformTypeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_waveformTypeSlider->addListener (this);

    addAndMakeVisible (m_detuneSlider = new Slider ("Detune Slider"));
    m_detuneSlider->setRange (0, 10, 0);
    m_detuneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_detuneSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_detuneSlider->addListener (this);

    addAndMakeVisible (m_distortionTypeSlider = new Slider ("Distortion Type Slider"));
    m_distortionTypeSlider->setRange (0, 10, 0);
    m_distortionTypeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_distortionTypeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_distortionTypeSlider->addListener (this);

    addAndMakeVisible (m_distortionAmtSlider = new Slider ("Distortion Amt Slider"));
    m_distortionAmtSlider->setRange (0, 10, 0);
    m_distortionAmtSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_distortionAmtSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_distortionAmtSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (240, 60);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscillatorEditor::~OscillatorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_waveformTypeSlider = nullptr;
    m_detuneSlider = nullptr;
    m_distortionTypeSlider = nullptr;
    m_distortionAmtSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscillatorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff424242));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OscillatorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_waveformTypeSlider->setBounds (6, 6, 48, 48);
    m_detuneSlider->setBounds (66, 6, 48, 48);
    m_distortionTypeSlider->setBounds (126, 6, 48, 48);
    m_distortionAmtSlider->setBounds (186, 6, 48, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscillatorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    
    const OwnedArray<AudioProcessorParameter>& params =
        dynamic_cast<AudioProcessorEditor*>(this->getParentComponent())->processor.getParameters();

    int offset = this->getParentComponent()->getIndexOfChildComponent(this) * 4;

    FloatParameter* waveformTypeParam = static_cast<FloatParameter*>(params[offset + 0]);
    FloatParameter* detuneParam = static_cast<FloatParameter*>(params[offset + 1]);
    FloatParameter* distortionTypeParam = static_cast<FloatParameter*>(params[offset + 2]);
    FloatParameter* distortionAmtParam = static_cast<FloatParameter*>(params[offset + 3]);

    float sliderValue = (float) sliderThatWasMoved->getValue();

    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_waveformTypeSlider)
    {
        //[UserSliderCode_m_waveformTypeSlider] -- add your slider handling code here..
        waveformTypeParam->setValueNotifyingHost(sliderValue);
        //[/UserSliderCode_m_waveformTypeSlider]
    }
    else if (sliderThatWasMoved == m_detuneSlider)
    {
        //[UserSliderCode_m_detuneSlider] -- add your slider handling code here..
        detuneParam->setValueNotifyingHost(sliderValue);
        //[/UserSliderCode_m_detuneSlider]
    }
    else if (sliderThatWasMoved == m_distortionTypeSlider)
    {
        //[UserSliderCode_m_distortionTypeSlider] -- add your slider handling code here..
        distortionTypeParam->setValueNotifyingHost(sliderValue);
        //[/UserSliderCode_m_distortionTypeSlider]
    }
    else if (sliderThatWasMoved == m_distortionAmtSlider)
    {
        //[UserSliderCode_m_distortionAmtSlider] -- add your slider handling code here..
        distortionAmtParam->setValueNotifyingHost(sliderValue);
        //[/UserSliderCode_m_distortionAmtSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscillatorEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="240" initialHeight="60">
  <BACKGROUND backgroundColour="ff424242"/>
  <SLIDER name="Waveform Type Slider" id="6bf52f32c05db73e" memberName="m_waveformTypeSlider"
          virtualName="" explicitFocusOrder="0" pos="6 6 48 48" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Detune Slider" id="caee4947212defec" memberName="m_detuneSlider"
          virtualName="" explicitFocusOrder="0" pos="66 6 48 48" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Distortion Type Slider" id="e18c7bc635c988a6" memberName="m_distortionTypeSlider"
          virtualName="" explicitFocusOrder="0" pos="126 6 48 48" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Distortion Amt Slider" id="ed44a77afcd55a16" memberName="m_distortionAmtSlider"
          virtualName="" explicitFocusOrder="0" pos="186 6 48 48" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
