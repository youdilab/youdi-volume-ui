/*
  ==============================================================================

    VolumeKnobLooknFeel.h
    Created: 20 Nov 2024 12:57:51pm
    Author:  Uditha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class VolumeKnobLooknFeel : public juce::LookAndFeel_V4
{
public:
    VolumeKnobLooknFeel()
        :imgVolumeKnob(juce::ImageCache::getFromMemory(BinaryData::Knob_png, BinaryData::Knob_pngSize))
    {
    }
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle,
        juce::Slider& slider) override
    {
        // Calculate rotation angle
        const float rotation = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);

        // Center the knob image
        const float centerX = x + width * 0.5f;
        const float centerY = y + height * 0.5f;

        // Scale the knob to fit within the bounds
        const float scale = juce::jmin(width / (float)imgVolumeKnob.getWidth(), height / (float)imgVolumeKnob.getHeight());

        // Apply rotation
        juce::AffineTransform transform = juce::AffineTransform::translation(-imgVolumeKnob.getWidth() * 0.5f, -imgVolumeKnob.getHeight() * 0.5f)
            .scaled(scale)
            .rotated(rotation)
            .translated(centerX, centerY);

        // Draw the image with the above transformation
        g.drawImageTransformed(imgVolumeKnob, transform, false);
    }

private:
    juce::Image imgVolumeKnob;
};