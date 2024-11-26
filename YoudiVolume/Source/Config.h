/*
  ==============================================================================

    Config.h
    Created: 19 Nov 2024 7:01:19pm
    Author:  Uditha

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace parameters
{
    struct audioParameterFloat
    {
        const juce::String id;
        const juce::String name;
        const float minValue;
        const float maxValue;
        const float defaultValue;
    };

    static const audioParameterFloat volume{"volume", "Volume", 0.0f, 1.0f, 0.0f};
};

namespace dimensions
{
    static const float pluginWidth = 266.25;
    static const float pluginHeight = 234.75;

    static const float xSldVolume = 55;
    static const float ySldVolume = 60;
    static const float widthSldVolume = 190;
    static const float heightSldVolume = 190;
}
