#include "PluginProcessor.h"
#include "PluginEditor.h"

FetchProcessor::FetchProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo()))
{
}

void FetchProcessor::prepareToPlay (double, int)
{
    // TODO: reset renderer playhead.
}

void FetchProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                   juce::MidiBuffer& midiMessages)
{
    buffer.clear();
    midiMessages.clear();
    // TODO: ask the playhead for BPM + position; render the current
    // note plan's events into midiMessages for this block, in sync.
}

juce::AudioProcessorEditor* FetchProcessor::createEditor()
{
    return new FetchEditor (*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FetchProcessor();
}
