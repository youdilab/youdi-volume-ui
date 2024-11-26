/*
  ==============================================================================

    VolumeKnobOne.h
    Created: 26 Nov 2024 3:43:00pm
    Author:  Uditha

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class VolumeKnobOne  : public juce::Slider
{
public:
    VolumeKnobOne(SliderStyle style, TextEntryBoxPosition textBoxPosition)
        :imgSpriteVolumeKnob(juce::ImageCache::getFromMemory(BinaryData::KnobSprite3D_png, BinaryData::KnobSprite3D_pngSize))
        ,Slider(style, textBoxPosition)
    {
    }

    void paint (juce::Graphics& g) override
    {
        const int nFrames = 60;
        const int frameWidth = imgSpriteVolumeKnob.getWidth()/nFrames;
        const int frameHeight = imgSpriteVolumeKnob.getHeight();

        int frameIndex = juce::jlimit(0, nFrames - 1, (int)std::round(getValue() * (nFrames - 1)));

        juce::Rectangle<int> frameRectangle(0, 0, frameWidth, frameHeight);

        g.drawImage(imgSpriteVolumeKnob, 0, 0, getWidth(), getHeight(), frameIndex * frameWidth, 0, frameWidth, frameHeight);
    }
private:
    juce::Image imgSpriteVolumeKnob;
};
