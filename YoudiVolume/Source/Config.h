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

    static const audioParameterFloat volume{"volume", "Volume", 0.0f, 1.0f, 0.5f};
};

namespace dimensions
{
    static const int pluginWidth = 300;
    static const int pluginHeight = 325;

    static const int xSldVolume = 55;
    static const int ySldVolume = 60;
    static const int widthSldVolume = 190;
    static const int heightSldVolume = 190;
}
