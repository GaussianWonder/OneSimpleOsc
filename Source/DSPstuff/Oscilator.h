/*
  ==============================================================================

    Oscilator.h
    Created: 25 Nov 2018 7:05:09pm
    Author:  virghi

  ==============================================================================
*/

#pragma once
#include "../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Oscilator    : public Component,
                     public ComboBox::Listener
{
public:
    Oscilator();
    ~Oscilator();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscilator)
};
