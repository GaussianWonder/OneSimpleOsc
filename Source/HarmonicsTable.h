/*
  ==============================================================================

    HarmonicsTable.h
    Created: 20 Nov 2018 2:41:33pm
    Author:  virghi

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "HarmonicSlider"
//#include "maximilian.h"		//might need it

class HarmonicsTable
{
	public:
		HarmonicSlider sliders[4];

		HarmonicsTable();
		~HarmonicsTable();

	private:
		void display();
		void calculate();

}

HarmonicsTable::HarmonicsTable(){		//constructor

}

HarmonicsTable::~HarmonicsTable(){		//destructor

}

HarmonicsTable::display(){

}

HarmonicsTable::calculate(){

}