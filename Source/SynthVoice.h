/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Nov 2018 2:55:49pm
    Author:  Teo

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice
{
public:

	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSound*>(sound) != nullptr;
	}
	//============================================ canPlaySound()

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition)
	{
		//called to start a new note
		env1.trigger = 1;

		level = velocity;
		frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		return;
	}
	//============================================ startNote()

	void stopNote(float velocity, bool allowTailOff)
	{
		//called to stop a note
		env1.trigger = 0;
		allowTailOff = true;

		if(velocity == 0)
			clearCurrentNote();
		return;
	}
	//============================================ stopNote()

	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
	{
		//Renders the next block of data for this voice

		env1.setAttack(800);
		env1.setDecay(200);
		env1.setSustain(0.75f);
		env1.setRelease(800);

		for(int sample = 0; sample < numSamples; ++sample){
			double sinWave = sinOsc.saw(frequency);
			double sinSound = env1.adsr(sinWave, env1.trigger) * level;
			double sinFilter = filter1.lores(sinSound, 200, 0.1);

			for(int channel = 0; channel < outputBuffer.getNumChannels(); ++channel){


				outputBuffer.addSample(channel, startSample, sinFilter);
			}

			++startSample;
		}

		return;
	}
	//============================================ renderNextBlock()

	void pitchWheelMoved(int newPitchWheelValue)
	{
		//Called to let the voice know that the pitch wheel has been moved


		return;
	}
	//============================================ pitchWheelMoved()

	void controllerMoved(int controllerNumber, int newControllerValue)
	{
		//Called to let the voice know that a midi controller has been moved


		return;
	}
	//============================================ controllerMoved()

private:
	double level;
	double frequency;

	maxiOsc sinOsc;
	maxiEnv env1;
	maxiFilter filter1;
};