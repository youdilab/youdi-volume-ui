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
    static const float scale_factor = 1.5;

    static const float pluginWidth = 1065/ scale_factor;
    static const float pluginHeight = 939/ scale_factor;

    static const float xSldVolume = 356/ scale_factor;
    static const float ySldVolume = 244/ scale_factor;
    static const float widthSldVolume = 354/ scale_factor;
    static const float heightSldVolume = 339/ scale_factor;

    static const float xLblVolume = 421 / scale_factor;
    static const float yLblVolume = 653 / scale_factor;
    static const float widthLblVolume = 248 / scale_factor;
    static const float heightLblVolume = 129 / scale_factor;
}
