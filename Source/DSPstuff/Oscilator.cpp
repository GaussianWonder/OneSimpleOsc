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
Oscilator::Oscilator(OneOscAudioProcessor& p) :
    processor(p), mySynth(p.getMySynth()), myVoice(p.getMyVoice())
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

    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(
        processor.tree,
        WAVE_TYPE,
        oscMenu 
      );

}

Oscilator::~Oscilator()
{
}

void Oscilator::paint (Graphics& g)
{

}

void Oscilator::comboBoxChanged(ComboBox* box)
{
    for(int i = 0; i < mySynth->getNumVoices(); ++i){
      if( (myVoice = dynamic_cast<SynthVoice*>(mySynth->getVoice(i))) ){
        myVoice->getOscType(processor.tree.getRawParameterValue(WAVE_TYPE));
      }
    }
}

void Oscilator::resized()
{
    Rectangle<int> area = getLocalBounds();     //shrinking a rectangle from every way 40px = .reduced(40)

    oscMenu.setBounds(area.removeFromTop(20));  //making it look smaller
}
