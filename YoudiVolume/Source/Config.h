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

    static const audioParameterFloat volume{"volume", "Volume", 0.0f, 100.0f, 50.0f};
};
