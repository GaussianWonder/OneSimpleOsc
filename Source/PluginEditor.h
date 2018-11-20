#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class OneOscAudioProcessorEditor  : public AudioProcessorEditor,
                    public Button::Listener
{
public:
    //==============================================================================
    OneOscAudioProcessorEditor (OneOscAudioProcessor&);
    ~OneOscAudioProcessorEditor();

    //==============================================================================

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    OneOscAudioProcessor& processor;

    //==============================================================================
    std::unique_ptr<GroupComponent> WTGroup;
    std::unique_ptr<TabbedComponent> WTEffects;
    std::unique_ptr<TextButton> WTImport;
    std::unique_ptr<TextButton> WTSave;
    std::unique_ptr<TextButton> WTRemap;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OneOscAudioProcessorEditor)
};
