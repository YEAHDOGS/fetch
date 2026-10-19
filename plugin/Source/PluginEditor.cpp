#include "PluginEditor.h"

FetchEditor::FetchEditor (FetchProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    setSize (520, 420);
    // TODO: build the chat UI (see docs/MVP.md).
}

void FetchEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (20.0f);
    g.drawText ("Fetch — talk to AI, make songs.", getLocalBounds(),
                juce::Justification::centred, true);
}

void FetchEditor::resized() {}
