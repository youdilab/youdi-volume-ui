/*
  ==============================================================================

    SsdDigit.h
    Created: 26 Nov 2024 7:38:20pm
    Author:  Uditha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SsdDigit : public juce::Component
{
public:
    SsdDigit()
        :imgSpriteDigit(juce::ImageCache::getFromMemory(BinaryData::DigitSprite3D_png, BinaryData::DigitSprite3D_pngSize))
    {
    }

    void setValue(int value)
    {
        int temp = juce::jlimit(0, 100, value);
        digit0 = temp / 100;
        temp = temp % 100;
        digit1 = temp/10;
        digit2 = temp % 10;
    }

    void paint(juce::Graphics& g) override
    {
        const int nFrames = 10;
        const int frameWidth = imgSpriteDigit.getWidth() / nFrames;
        const int frameHeight = imgSpriteDigit.getHeight();

        int frameIndex0 = juce::jlimit(0, nFrames, digit0);
        int frameIndex1 = juce::jlimit(0, nFrames - 1, digit1);
        int frameIndex2 = juce::jlimit(0, nFrames - 1, digit2);


        g.drawImage(imgSpriteDigit, 0, 0, getWidth()/3, getHeight(), digit0 * frameWidth, 0, frameWidth, frameHeight);
        g.drawImage(imgSpriteDigit, 56, 0, getWidth()/3, getHeight(), digit1 * frameWidth, 0, frameWidth, frameHeight);
        g.drawImage(imgSpriteDigit, 112, 0, getWidth()/3, getHeight(), digit2 * frameWidth, 0, frameWidth, frameHeight);
    }
private:
    int digit0 =0, digit1=0, digit2=0;
    juce::Image imgSpriteDigit;
};