#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "GUIComponents/ClassicsGUI.h"

//==============================================================================
OneOscAudioProcessorEditor::OneOscAudioProcessorEditor (OneOscAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    addAndMakeVisible(&oscGui);

    WTGroup.reset (new GroupComponent ("wtGroup",
                                       TRANS("Wavetable Oscilator")));
    addAndMakeVisible (WTGroup.get());
    WTGroup->setTextLabelPosition (Justification::centred);

    WTEffects.reset (new TabbedComponent (TabbedButtonBar::TabsAtBottom));
    addAndMakeVisible (WTEffects.get());
    WTEffects->setTabBarDepth (25);
    WTEffects->addTab (TRANS("Classics"), Colours::lightgrey, new ClassicsGUI(processor.getMySynth(), processor.getMyVoice()), false);
    WTEffects->addTab (TRANS("Extra transform"), Colours::lightgrey, 0, false);
    WTEffects->setCurrentTabIndex (0);

    WTImport.reset (new TextButton ("wtImport"));
    addAndMakeVisible (WTImport.get());
    WTImport->setTooltip (TRANS("Import a wavetable (select a .wav file)"));
    WTImport->setExplicitFocusOrder (1);
    WTImport->setButtonText (TRANS("Import"));
    WTImport->addListener (this);
    WTImport->setColour (TextButton::buttonColourId, Colour (0xffb5a556));

    WTSave.reset (new TextButton ("wtSave"));
    addAndMakeVisible (WTSave.get());
    WTSave->setTooltip (TRANS("Save the wavetable (Ater all Effects)"));
    WTSave->setExplicitFocusOrder (1);
    WTSave->setButtonText (TRANS("Save"));
    WTSave->addListener (this);
    WTSave->setColour (TextButton::buttonColourId, Colour (0xff56b576));

    WTRemap.reset (new TextButton ("wtRemap"));
    addAndMakeVisible (WTRemap.get());
    WTRemap->setTooltip (TRANS("Remap the Wavetable + Effects (Resample)"));
    WTRemap->setExplicitFocusOrder (1);
    WTRemap->setButtonText (TRANS("Remap"));
    WTRemap->addListener (this);
    WTRemap->setColour (TextButton::buttonColourId, Colour (0xff85b556));

    setSize (1000, 700);
}

OneOscAudioProcessorEditor::~OneOscAudioProcessorEditor()
{
    WTGroup = nullptr;
    WTEffects = nullptr;
    WTImport = nullptr;
    WTSave = nullptr;
    WTRemap = nullptr;
}

//==============================================================================
void OneOscAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colour (0xff323e44));
    {
        int x = proportionOfWidth (0.036f), y = proportionOfHeight (0.0637f), width = proportionOfWidth (0.2214f), height = proportionOfHeight (0.2903f);
        Colour fillColour = Colour (0xff20b4b8);
        Colour strokeColour = Colour (0xff1e2426);

        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);
    }

    {
        int x = proportionOfWidth (0.4324f), y = proportionOfHeight (0.0637f), width = proportionOfWidth (0.5354f), height = proportionOfHeight (0.2903f);
        Colour fillColour = Colour (0xff2a8da5);
        Colour strokeColour = Colour (0xff1e1d22);

        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);
    }

}

void OneOscAudioProcessorEditor::resized()
{
    int x = proportionOfWidth (0.036f), y = proportionOfHeight (0.0637f), width = proportionOfWidth (0.2214f), height = 200, space = proportionOfHeight (0.2903f);
    oscGui.setBounds(x, y + space, width, height);

    WTGroup->setBounds (proportionOfWidth (0.009f), proportionOfHeight (0.0142f), proportionOfWidth (0.9781f), proportionOfHeight (0.4673f));
    WTEffects->setBounds (proportionOfWidth (0.009f), proportionOfHeight (0.4956f), proportionOfWidth (0.9781f), proportionOfHeight (0.4956f));
    WTImport->setBounds (proportionOfWidth (0.2767f), proportionOfHeight (0.0708f), proportionOfWidth (0.1351f), proportionOfHeight (0.0425f));
    WTSave->setBounds (proportionOfWidth (0.2767f), proportionOfHeight (0.1274f), proportionOfWidth (0.1351f), proportionOfHeight (0.0425f));
    WTRemap->setBounds (proportionOfWidth (0.2767f), proportionOfHeight (0.1841f), proportionOfWidth (0.1351f), proportionOfHeight (0.0425f));
}

void OneOscAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == WTImport.get()){

    }
    else if (buttonThatWasClicked == WTSave.get()){

    }
    else if (buttonThatWasClicked == WTRemap.get()){

    }
}

void OneOscAudioProcessorEditor::sliderValueChanged(Slider* slider)
{

}