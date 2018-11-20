/*
  ==============================================================================

    SynthSound.h
    Created: 19 Nov 2018 2:55:37pm
    Author:  Teo

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:

	bool appliesToNote(int midiNum)
	{
		return true;
	}

	bool appliesToChannel(int channelNum)
	{
		return true;
	}

private:


};
