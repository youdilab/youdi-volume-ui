/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
YoudiVolumeAudioProcessorEditor::YoudiVolumeAudioProcessorEditor (YoudiVolumeAudioProcessor& p, juce::AudioProcessorValueTreeState& valueTree)
    : AudioProcessorEditor (&p), audioProcessor (p)
    , apvts(valueTree)
    , sldVolume(juce::Slider::SliderStyle::Rotary,juce::Slider::TextEntryBoxPosition::TextBoxBelow)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 650);

    addAndMakeVisible(sldVolume);

    attchVolume.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(apvts, parameters::volume.id, sldVolume));
}

YoudiVolumeAudioProcessorEditor::~YoudiVolumeAudioProcessorEditor()
{
}

//==============================================================================
void YoudiVolumeAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void YoudiVolumeAudioProcessorEditor::resized()
{
    sldVolume.setBounds(110, 120, 380, 380);
}
