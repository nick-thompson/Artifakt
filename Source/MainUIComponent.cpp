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

#include "MainUIComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainUIComponent::MainUIComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (m_topOscEditor = new OscillatorEditor());
    addAndMakeVisible (m_bottomOscEditor = new OscillatorEditor());
    addAndMakeVisible (m_oscBGroup = new GroupComponent ("Osc B Group",
                                                         TRANS("OSCB")));
    m_oscBGroup->setTextLabelPosition (Justification::centredLeft);
    m_oscBGroup->setColour (GroupComponent::outlineColourId, Colour (0xff303030));
    m_oscBGroup->setColour (GroupComponent::textColourId, Colour (0xff303030));

    addAndMakeVisible (m_oscAGroup = new GroupComponent ("Osc A Group",
                                                         TRANS("OSCA")));
    m_oscAGroup->setTextLabelPosition (Justification::centredLeft);
    m_oscAGroup->setColour (GroupComponent::outlineColourId, Colour (0xff303030));
    m_oscAGroup->setColour (GroupComponent::textColourId, Colour (0xff303030));

    addAndMakeVisible (m_slideGroup = new GroupComponent ("Slide Group",
                                                          TRANS("SLIDE")));
    m_slideGroup->setColour (GroupComponent::outlineColourId, Colour (0xff303030));
    m_slideGroup->setColour (GroupComponent::textColourId, Colour (0xff303030));

    addAndMakeVisible (m_bottomOscGain = new Slider ("Bottom Osc Gain"));
    m_bottomOscGain->setRange (0, 1, 0);
    m_bottomOscGain->setSliderStyle (Slider::RotaryVerticalDrag);
    m_bottomOscGain->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_bottomOscGain->setColour (Slider::thumbColourId, Colour (0xff1de9b6));
    m_bottomOscGain->setColour (Slider::trackColourId, Colour (0x00000000));
    m_bottomOscGain->setColour (Slider::rotarySliderFillColourId, Colour (0xff1de9b6));
    m_bottomOscGain->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff212121));
    m_bottomOscGain->setColour (Slider::textBoxTextColourId, Colour (0xff212121));
    m_bottomOscGain->setColour (Slider::textBoxBackgroundColourId, Colour (0x00000000));
    m_bottomOscGain->setColour (Slider::textBoxHighlightColourId, Colour (0xff1de9b6));
    m_bottomOscGain->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    m_bottomOscGain->addListener (this);

    addAndMakeVisible (m_slideAmountSlider = new Slider ("Slider Amount Slider"));
    m_slideAmountSlider->setRange (0, 1, 0);
    m_slideAmountSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    m_slideAmountSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    m_slideAmountSlider->setColour (Slider::thumbColourId, Colour (0xff1de9b6));
    m_slideAmountSlider->setColour (Slider::trackColourId, Colour (0x00000000));
    m_slideAmountSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff1de9b6));
    m_slideAmountSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff212121));
    m_slideAmountSlider->setColour (Slider::textBoxTextColourId, Colour (0xff212121));
    m_slideAmountSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00000000));
    m_slideAmountSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff1de9b6));
    m_slideAmountSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00000000));
    m_slideAmountSlider->addListener (this);

    addAndMakeVisible (m_detuneLabel = new Label ("Detune Label",
                                                  TRANS("AMOUNT")));
    m_detuneLabel->setFont (Font ("Avenir Next", 14.00f, Font::plain));
    m_detuneLabel->setJustificationType (Justification::centred);
    m_detuneLabel->setEditable (false, false, false);
    m_detuneLabel->setColour (Label::textColourId, Colour (0xff212121));
    m_detuneLabel->setColour (TextEditor::textColourId, Colour (0xff212121));
    m_detuneLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_detuneLabel->setColour (TextEditor::highlightColourId, Colour (0xff1de9b6));

    addAndMakeVisible (m_detuneLabel2 = new Label ("Detune Label",
                                                   TRANS("GAIN\n")));
    m_detuneLabel2->setFont (Font ("Avenir Next", 14.00f, Font::plain));
    m_detuneLabel2->setJustificationType (Justification::centred);
    m_detuneLabel2->setEditable (false, false, false);
    m_detuneLabel2->setColour (Label::textColourId, Colour (0xff212121));
    m_detuneLabel2->setColour (TextEditor::textColourId, Colour (0xff212121));
    m_detuneLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    m_detuneLabel2->setColour (TextEditor::highlightColourId, Colour (0xff1de9b6));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (288, 186);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainUIComponent::~MainUIComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_topOscEditor = nullptr;
    m_bottomOscEditor = nullptr;
    m_oscBGroup = nullptr;
    m_oscAGroup = nullptr;
    m_slideGroup = nullptr;
    m_bottomOscGain = nullptr;
    m_slideAmountSlider = nullptr;
    m_detuneLabel = nullptr;
    m_detuneLabel2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainUIComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff424242));

    g.setColour (Colour (0xff303030));
    g.fillRect (199, 122, 2, 32);

    g.setColour (Colour (0xff212121));
    g.setFont (Font ("Nanum Pen Script", 15.00f, Font::plain));
    g.drawText (TRANS("ARTIFAKT 1.0"),
                208, 82, 66, 30,
                Justification::centredRight, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainUIComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    m_topOscEditor->setBounds (16, 16, 176, 68);
    m_bottomOscEditor->setBounds (16, 104, 176, 68);
    m_oscBGroup->setBounds (8, 96, 272, 80);
    m_oscAGroup->setBounds (8, 8, 192, 80);
    m_slideGroup->setBounds (200, 8, 80, 80);
    m_bottomOscGain->setBounds (216, 112, 48, 48);
    m_slideAmountSlider->setBounds (216, 24, 48, 48);
    m_detuneLabel->setBounds (216, 64, 48, 20);
    m_detuneLabel2->setBounds (216, 152, 48, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainUIComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_bottomOscGain)
    {
        //[UserSliderCode_m_bottomOscGain] -- add your slider handling code here..
        //[/UserSliderCode_m_bottomOscGain]
    }
    else if (sliderThatWasMoved == m_slideAmountSlider)
    {
        //[UserSliderCode_m_slideAmountSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_slideAmountSlider]
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

<JUCER_COMPONENT documentType="Component" className="MainUIComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="288" initialHeight="186">
  <BACKGROUND backgroundColour="ff424242">
    <RECT pos="199 122 2 32" fill="solid: ff303030" hasStroke="0"/>
    <TEXT pos="208 82 66 30" fill="solid: ff212121" hasStroke="0" text="ARTIFAKT 1.0"
          fontname="Nanum Pen Script" fontsize="15" bold="0" italic="0"
          justification="34"/>
  </BACKGROUND>
  <JUCERCOMP name="" id="18fe22fbce902c12" memberName="m_topOscEditor" virtualName=""
             explicitFocusOrder="0" pos="16 16 176 68" sourceFile="OscillatorEditor.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="e8d4e82a3d899f31" memberName="m_bottomOscEditor"
             virtualName="" explicitFocusOrder="0" pos="16 104 176 68" sourceFile="OscillatorEditor.cpp"
             constructorParams=""/>
  <GROUPCOMPONENT name="Osc B Group" id="e7cd32bd8740a799" memberName="m_oscBGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 96 272 80" outlinecol="ff303030"
                  textcol="ff303030" title="OSCB" textpos="33"/>
  <GROUPCOMPONENT name="Osc A Group" id="185fc8bee23fc9a4" memberName="m_oscAGroup"
                  virtualName="" explicitFocusOrder="0" pos="8 8 192 80" outlinecol="ff303030"
                  textcol="ff303030" title="OSCA" textpos="33"/>
  <GROUPCOMPONENT name="Slide Group" id="a3108118198c099c" memberName="m_slideGroup"
                  virtualName="" explicitFocusOrder="0" pos="200 8 80 80" outlinecol="ff303030"
                  textcol="ff303030" title="SLIDE"/>
  <SLIDER name="Bottom Osc Gain" id="aedfe51a3e31f5db" memberName="m_bottomOscGain"
          virtualName="" explicitFocusOrder="0" pos="216 112 48 48" thumbcol="ff1de9b6"
          trackcol="0" rotarysliderfill="ff1de9b6" rotaryslideroutline="ff212121"
          textboxtext="ff212121" textboxbkgd="0" textboxhighlight="ff1de9b6"
          textboxoutline="0" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Slider Amount Slider" id="7173876185bb31af" memberName="m_slideAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="216 24 48 48" thumbcol="ff1de9b6"
          trackcol="0" rotarysliderfill="ff1de9b6" rotaryslideroutline="ff212121"
          textboxtext="ff212121" textboxbkgd="0" textboxhighlight="ff1de9b6"
          textboxoutline="0" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Detune Label" id="a1f93c7386977e20" memberName="m_detuneLabel"
         virtualName="" explicitFocusOrder="0" pos="216 64 48 20" textCol="ff212121"
         edTextCol="ff212121" edBkgCol="0" hiliteCol="ff1de9b6" labelText="AMOUNT"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir Next" fontsize="14" bold="0" italic="0" justification="36"/>
  <LABEL name="Detune Label" id="23e00147d67dd053" memberName="m_detuneLabel2"
         virtualName="" explicitFocusOrder="0" pos="216 152 48 20" textCol="ff212121"
         edTextCol="ff212121" edBkgCol="0" hiliteCol="ff1de9b6" labelText="GAIN&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Avenir Next" fontsize="14" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
