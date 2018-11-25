/*
  ==============================================================================

    Oscilator.cpp
    Created: 25 Nov 2018 7:05:09pm
    Author:  virghi

  ==============================================================================
*/

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Oscilator.h"

//==============================================================================
Oscilator::Oscilator()
{
    setSize(200, 200);

    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Triangle", 3);
    oscMenu.addItem("Square", 4);
    oscMenu.addItem("Pulse", 5);
    oscMenu.addItem("Custom", 6);

    addAndMakeVisible(oscMenu);
    oscMenu.addListener(this);

    oscMenu.setJustificationType(Justification::centred);
}

Oscilator::~Oscilator()
{
}

void Oscilator::paint (Graphics& g)
{
    // g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // g.setColour (Colours::grey);
    // g.drawRect (getLocalBounds(), 1);

    // g.setColour (Colours::white);
    // g.setFont (14.0f);
    // g.drawText ("Oscilator", getLocalBounds(), Justification::centred, true);
}

void Oscilator::comboBoxChanged(ComboBox* box)
{
    //Implementation is not necessary
}

void Oscilator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);  //shrinking a rectangle from every way 40px

    oscMenu.setBounds(area.removeFromTop(20));
}
