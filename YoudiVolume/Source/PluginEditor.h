/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class YoudiVolumeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    YoudiVolumeAudioProcessorEditor (YoudiVolumeAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~YoudiVolumeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    YoudiVolumeAudioProcessor& audioProcessor;

    juce::AudioProcessorValueTreeState& apvts;

    //GUI components
    juce::Slider sldVolume;

    //Parameter-Component attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attchVolume;

    //Background Image
    juce::Image imgPluginBg;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoudiVolumeAudioProcessorEditor)
};
