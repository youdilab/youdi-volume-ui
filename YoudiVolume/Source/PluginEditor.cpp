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
    , sldVolume(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,juce::Slider::TextEntryBoxPosition::TextBoxBelow)
    , imgPluginBg(juce::ImageFileFormat::loadFrom(
        juce::MemoryInputStream(BinaryData::Background_png,
            BinaryData::Background_pngSize,
            false)))
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (dimensions::pluginWidth, dimensions::pluginHeight);

    addAndMakeVisible(sldVolume);

    attchVolume.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(apvts, parameters::volume.id, sldVolume));
}

YoudiVolumeAudioProcessorEditor::~YoudiVolumeAudioProcessorEditor()
{
}

//==============================================================================
void YoudiVolumeAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.drawImage(imgPluginBg, getLocalBounds().toFloat(),juce::RectanglePlacement::stretchToFit,false);
}

void YoudiVolumeAudioProcessorEditor::resized()
{
    sldVolume.setBounds(dimensions::xSldVolume, dimensions::ySldVolume, dimensions::widthSldVolume, dimensions::heightSldVolume);
}
