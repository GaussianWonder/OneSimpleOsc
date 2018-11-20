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
	    ClassicsGUI (Synthesiser* pSynth, SynthVoice* pVoice){
	    	_mySynth = pSynth;
	    	_myVoice = pVoice;

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
	    	atkS.setBounds(10, 10, 20, 100);
	    	decS.setBounds(40, 10, 20, 100);
	    	susS.setBounds(70, 10, 20, 100);
	    	relS.setBounds(100, 10, 20, 100);
	    }

	    void comboBoxChanged (ComboBox* comboBoxThatHasChanged){

	    }

	    void sliderValueChanged (Slider* sliderThatWasMoved){
	    	for(int i = 0; i < _mySynth->getNumVoices(); ++i){

	    		if( (_myVoice = dynamic_cast<SynthVoice*>(_mySynth->getVoice(i))) ){
	    			//Make use of SETTERS
	    			if(sliderThatWasMoved == &atkS)
		    			_myVoice->setAtkS(atkS.getValue());
			    	else if(sliderThatWasMoved == &decS)
		    			_myVoice->setDecS(decS.getValue());
			    	else if(sliderThatWasMoved == &susS)
		    			_myVoice->setSusS(susS.getValue());
			    	else if(sliderThatWasMoved == &relS)
		    			_myVoice->setRelS(relS.getValue());
	    		}

	    	}
	    }

	    
	private:
		Synthesiser* _mySynth;
		SynthVoice* _myVoice;

	    // Label atkV, decV, susV, relV;
	    Slider atkS, decS, susS, relS;
	   	ComboBox waveForm;

	    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ClassicsGUI)
};
