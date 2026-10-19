#pragma once
#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"

// Chat-first editor: prompt box, conversation view, role selector,
// humanize slider. Keep it keyboard-first — Enter sends.
class FetchEditor : public juce::AudioProcessorEditor
{
public:
    explicit FetchEditor (FetchProcessor&);
    ~FetchEditor() override = default;
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    FetchProcessor& processorRef;
    // TODO: juce::TextEditor promptInput; juce::TextEditor transcript;
    // TODO: juce::ComboBox roleSelector; juce::Slider humanize;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FetchEditor)
};
