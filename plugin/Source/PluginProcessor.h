#pragma once
#include <juce_audio_processors/juce_audio_processors.h>

// Fetch: prompt-to-MIDI generator. Holds the current note plan and renders
// it as looping MIDI, sample-accurately, against the host transport.
// All model/network work happens off the audio thread (see docs/ARCHITECTURE.md).
class FetchProcessor : public juce::AudioProcessor
{
public:
    FetchProcessor();
    ~FetchProcessor() override = default;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override {}
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "Fetch"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return true; }
    bool isMidiEffect() const override { return true; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int) override {}
    const juce::String getProgramName (int) override { return {}; }
    void changeProgramName (int, const juce::String&) override {}

    void getStateInformation (juce::MemoryBlock&) override {}
    void setStateInformation (const void*, int) override {}

private:
    // TODO: NotePlan plan; MidiRenderer renderer; ModelBackend backend;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FetchProcessor)
};
