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
    m_waveformTypeSlider->setRange (0, 3, 0.166);
    m_waveformTypeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_waveformTypeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_waveformTypeSlider->setColour (Slider::thumbColourId, Colour (0xff1de9b6));
    m_waveformTypeSlider->setColour (Slider::trackColourId, Colour (0x00000000));
    m_waveformTypeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff1de9b6));
    m_waveformTypeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff212121));
    m_waveformTypeSlider->setColour (Slider::textBoxTextColourId, Colour (0xff212121));
    m_waveformTypeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00000000));
    m_waveformTypeSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff1de9b6));
    m_waveformTypeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    m_waveformTypeSlider->addListener (this);

    addAndMakeVisible (m_detuneLabel = new Label ("Detune Label",
                                                  TRANS("DETUNE")));
    m_detuneLabel->setFont (Font ("Avenir Next", 14.00f, Font::plain));
    m_detuneLabel->setJustificationType (Justification::centred);
    m_detuneLabel->setEditable (false, false, false);
    m_detuneLabel->setColour (Label::textColourId, Colour (0xff212121));
    m_detuneLabel->setColour (TextEditor::textColourId, Colour (0xff212121));
    m_detuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_detuneLabel->setColour (TextEditor::highlightColourId, Colour (0xff1de9b6));

    addAndMakeVisible (m_waveTypeLabel = new Label ("Waveform Type Label",
                                                    TRANS("WAVE")));
    m_waveTypeLabel->setFont (Font ("Avenir Next", 14.00f, Font::plain));
    m_waveTypeLabel->setJustificationType (Justification::centred);
    m_waveTypeLabel->setEditable (false, false, false);
    m_waveTypeLabel->setColour (Label::textColourId, Colour (0xff212121));
    m_waveTypeLabel->setColour (TextEditor::textColourId, Colour (0xff212121));
    m_waveTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_waveTypeLabel->setColour (TextEditor::highlightColourId, Colour (0xff1de9b6));

    addAndMakeVisible (m_detuneSlider = new Slider ("Detune Slider"));
    m_detuneSlider->setRange (-100, 100, 1);
    m_detuneSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_detuneSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_detuneSlider->setColour (Slider::thumbColourId, Colour (0xff1de9b6));
    m_detuneSlider->setColour (Slider::trackColourId, Colour (0x00000000));
    m_detuneSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff1de9b6));
    m_detuneSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff212121));
    m_detuneSlider->setColour (Slider::textBoxTextColourId, Colour (0xff212121));
    m_detuneSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00000000));
    m_detuneSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff1de9b6));
    m_detuneSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    m_detuneSlider->addListener (this);

    addAndMakeVisible (m_distortionSlider = new Slider ("Distortion Slider"));
    m_distortionSlider->setRange (0, 1, 0);
    m_distortionSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_distortionSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_distortionSlider->setColour (Slider::thumbColourId, Colour (0xff1de9b6));
    m_distortionSlider->setColour (Slider::trackColourId, Colour (0x00000000));
    m_distortionSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff1de9b6));
    m_distortionSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff212121));
    m_distortionSlider->setColour (Slider::textBoxTextColourId, Colour (0xff212121));
    m_distortionSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00000000));
    m_distortionSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff1de9b6));
    m_distortionSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    m_distortionSlider->addListener (this);

    addAndMakeVisible (m_distLabel = new Label ("Distortion Label",
                                                TRANS("DIST.")));
    m_distLabel->setFont (Font ("Avenir Next", 14.00f, Font::plain));
    m_distLabel->setJustificationType (Justification::centred);
    m_distLabel->setEditable (false, false, false);
    m_distLabel->setColour (Label::textColourId, Colour (0xff212121));
    m_distLabel->setColour (TextEditor::textColourId, Colour (0xff212121));
    m_distLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_distLabel->setColour (TextEditor::highlightColourId, Colour (0xff1de9b6));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (176, 68);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscillatorEditor::~OscillatorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_waveformTypeSlider = nullptr;
    m_detuneLabel = nullptr;
    m_waveTypeLabel = nullptr;
    m_detuneSlider = nullptr;
    m_distortionSlider = nullptr;
    m_distLabel = nullptr;


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

    m_waveformTypeSlider->setBounds (8, 8, 48, 48);
    m_detuneLabel->setBounds (64, 48, 48, 20);
    m_waveTypeLabel->setBounds (8, 48, 48, 20);
    m_detuneSlider->setBounds (64, 8, 48, 48);
    m_distortionSlider->setBounds (120, 8, 48, 48);
    m_distLabel->setBounds (120, 48, 48, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscillatorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]

    const OwnedArray<AudioProcessorParameter>& params =
        dynamic_cast<AudioProcessorEditor*>(this->getParentComponent())->processor.getParameters();

    int offset = this->getParentComponent()->getIndexOfChildComponent(this) * 3;

    FloatParameter* waveformTypeParam = static_cast<FloatParameter*>(params[offset + 0]);
    FloatParameter* detuneParam = static_cast<FloatParameter*>(params[offset + 1]);
    FloatParameter* distortionParam = static_cast<FloatParameter*>(params[offset + 2]);

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
    else if (sliderThatWasMoved == m_distortionSlider)
    {
        //[UserSliderCode_m_distortionSlider] -- add your slider handling code here..
        distortionParam->setValueNotifyingHost(sliderValue);
        //[/UserSliderCode_m_distortionSlider]
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
                 fixedSize="1" initialWidth="176" initialHeight="68">
  <BACKGROUND backgroundColour="ff424242"/>
  <SLIDER name="Waveform Type Slider" id="6bf52f32c05db73e" memberName="m_waveformTypeSlider"
          virtualName="" explicitFocusOrder="0" pos="8 8 48 48" thumbcol="ff1de9b6"
          trackcol="0" rotarysliderfill="ff1de9b6" rotaryslideroutline="ff212121"
          textboxtext="ff212121" textboxbkgd="0" textboxhighlight="ff1de9b6"
          textboxoutline="0" min="0" max="3" int="0.16600000000000000866"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Detune Label" id="a1f93c7386977e20" memberName="m_detuneLabel"
         virtualName="" explicitFocusOrder="0" pos="64 48 48 20" textCol="ff212121"
         edTextCol="ff212121" edBkgCol="0" hiliteCol="ff1de9b6" labelText="DETUNE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir Next" fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="Waveform Type Label" id="be04e04491416e57" memberName="m_waveTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="8 48 48 20" textCol="ff212121"
         edTextCol="ff212121" edBkgCol="0" hiliteCol="ff1de9b6" labelText="WAVE"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir Next" fontsize="14" bold="0" italic="0" justification="36"/>
  <SLIDER name="Detune Slider" id="d1daad0e26566e09" memberName="m_detuneSlider"
          virtualName="" explicitFocusOrder="0" pos="64 8 48 48" thumbcol="ff1de9b6"
          trackcol="0" rotarysliderfill="ff1de9b6" rotaryslideroutline="ff212121"
          textboxtext="ff212121" textboxbkgd="0" textboxhighlight="ff1de9b6"
          textboxoutline="0" min="-100" max="100" int="1" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Distortion Slider" id="aedfe51a3e31f5db" memberName="m_distortionSlider"
          virtualName="" explicitFocusOrder="0" pos="120 8 48 48" thumbcol="ff1de9b6"
          trackcol="0" rotarysliderfill="ff1de9b6" rotaryslideroutline="ff212121"
          textboxtext="ff212121" textboxbkgd="0" textboxhighlight="ff1de9b6"
          textboxoutline="0" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Distortion Label" id="655def837cafb84e" memberName="m_distLabel"
         virtualName="" explicitFocusOrder="0" pos="120 48 48 20" textCol="ff212121"
         edTextCol="ff212121" edBkgCol="0" hiliteCol="ff1de9b6" labelText="DIST."
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir Next" fontsize="14" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
