/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Config.h"

//==============================================================================
/**
*/
class YoudiVolumeAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    YoudiVolumeAudioProcessor();
    ~YoudiVolumeAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    juce::AudioProcessorValueTreeState parameters;

    //Adding parameters to layout
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        juce::AudioProcessorValueTreeState::ParameterLayout params;

        //Lambda function to add juce::AudioParameterFloat
        const auto addFloatParameter = [&](const parameters::audioParameterFloat& paramFloat)
        {
            params.add(std::make_unique<juce::AudioParameterFloat>(paramFloat.id, paramFloat.name, paramFloat.minValue, paramFloat.maxValue, paramFloat.defaultValue));
        };

        //Adding parameters using above lambda functions.
        addFloatParameter(parameters::volume);

        return params;
    }

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoudiVolumeAudioProcessor)
};
