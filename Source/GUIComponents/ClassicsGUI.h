/*
  ==============================================================================

    ClassicsGUI.h
    Created: 20 Nov 2018 3:35:02pm
    Author:  virghi
	
	GUI for the classics tab
  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../SynthVoice.h"
#include "../SynthSound.h"

class ClassicsGUI : public Component,
                    public ComboBox::Listener,
                    public Slider::Listener
{
	public:
	    ClassicsGUI (OneOscAudioProcessor* p){
	    	processor = p;
	    	mySynth = processor->getMySynth();
	    	myVoice = processor->getMyVoice();

	    	atkS.setSliderStyle(Slider::SliderStyle::LinearVertical);
	    	atkS.setRange(0.1f, 5000.0f);
	    	atkS.setValue(200.0f);
	    	atkS.addListener(this);
	    	addAndMakeVisible(&atkS);

	    	decS.setSliderStyle(Slider::SliderStyle::LinearVertical);
	    	decS.setRange(1.0f, 5000.0f);
	    	decS.setValue(21.0f);
	    	decS.addListener(this);
	    	addAndMakeVisible(&decS);

	    	susS.setSliderStyle(Slider::SliderStyle::LinearVertical);
	    	susS.setRange(0.0f, 1.0f);
	    	susS.setValue(0.8f);
	    	susS.addListener(this);
	    	addAndMakeVisible(&susS);

	    	relS.setSliderStyle(Slider::SliderStyle::LinearVertical);
	    	relS.setRange(0.1f, 5000.0f);
	    	relS.setValue(300.0f);
	    	relS.addListener(this);
	    	addAndMakeVisible(&relS);
	    }

	    ~ClassicsGUI (){

	    }

	    void paint (Graphics& g){

	    }

	    void resized (){
	    	const int spacing = 10;
	    	const int envSpacing = 20;
	    	const int envLongitude = 100;

	    	atkS.setBounds(spacing/* *1+envSpacing*0 */,spacing, envSpacing, envLongitude);
	    	decS.setBounds(spacing * 2 + envSpacing, 	spacing, envSpacing, envLongitude);
	    	susS.setBounds(spacing * 3 + envSpacing * 2,spacing, envSpacing, envLongitude);
	    	relS.setBounds(spacing * 4 + envSpacing * 3,spacing, envSpacing, envLongitude);
	    }

	    void sliderValueChanged (Slider* sliderThatWasMoved){

	    	for(int i = 0; i < mySynth->getNumVoices(); ++i){

	    		if( (myVoice = dynamic_cast<SynthVoice*>(mySynth->getVoice(i))) ){
	    			//Make use of SETTERS
	    			if(sliderThatWasMoved == &atkS)
		    			myVoice->setAtkS(atkS.getValue());
			    	else if(sliderThatWasMoved == &decS)
		    			myVoice->setDecS(decS.getValue());
			    	else if(sliderThatWasMoved == &susS)
		    			myVoice->setSusS(susS.getValue());
			    	else if(sliderThatWasMoved == &relS)
		    			myVoice->setRelS(relS.getValue());
	    		}

	    	}
	    }

	    void comboBoxChanged (ComboBox* comboBoxThatHasChanged){

	    }

	    
	private:
		OneOscAudioProcessor* processor;		//link to audio processor
		Synthesiser* mySynth;
		SynthVoice* myVoice;
		
	    // Label atkV, decV, susV, relV;
	    Slider atkS, decS, susS, relS;

	    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClassicsGUI)
};
