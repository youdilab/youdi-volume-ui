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
    , sldVolume(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,juce::Slider::TextEntryBoxPosition::NoTextBox)
    , imgPluginBg(juce::ImageFileFormat::loadFrom(
        juce::MemoryInputStream(BinaryData::Background3D_png,
            BinaryData::Background3D_pngSize,
            false)))
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (dimensions::pluginWidth, dimensions::pluginHeight);

    addAndMakeVisible(sldVolume);
    addAndMakeVisible(lblVolume);
    
    lblVolume.setValue(0);

    sldVolume.onValueChange = [this]()
    {        
        lblVolume.setValue(sldVolume.getValue() * 100);
        lblVolume.repaint();
    };

    attchVolume.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(apvts, parameters::volume.id, sldVolume));
}

YoudiVolumeAudioProcessorEditor::~YoudiVolumeAudioProcessorEditor()
{
    sldVolume.setLookAndFeel(nullptr);
}

//==============================================================================
void YoudiVolumeAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.drawImage(imgPluginBg, getLocalBounds().toFloat(),juce::RectanglePlacement::stretchToFit,false);
}

void YoudiVolumeAudioProcessorEditor::resized()
{
    sldVolume.setBounds(dimensions::xSldVolume, dimensions::ySldVolume, dimensions::widthSldVolume, dimensions::heightSldVolume);
    lblVolume.setBounds(dimensions::xLblVolume,dimensions::yLblVolume,dimensions::widthLblVolume,dimensions::heightLblVolume);
}