# Fetch

**Talk to AI. Make songs in Ableton.**

Fetch is a VST3 plugin by DOGS that lives on a MIDI track in Ableton Live.
Type what you want — *"dark minor bassline, 124 BPM, syncopated"* — and Fetch
generates the MIDI and plays it straight into your track. Ask for a variation,
a chord bed, a drum pattern. It fetches.

- Chat panel inside the plugin — no browser, no tab-switching
- Generates melody, bass, chords and drums as live MIDI
- Locked to your session: host tempo, key, and loop length
- Runs on **local models** (LM Studio / Ollama) or cloud APIs — your call
- No account, no login wall. Open it and make music.

## How it works

Prompt → AI returns a structured note plan (JSON) → Fetch renders it as MIDI
in sync with the host. Follow-up prompts edit the plan: *"same, but sadder"*,
*"half-time the drums"*, *"add a top line"*.

## Status

Skeleton. Architecture and MVP spec in `docs/`. Plugin scaffold in `plugin/`
(JUCE, VST3). Phase 2 adds a Max for Live companion so Fetch can reach into
the session itself — create tracks, drop clips, arrange.

---
*This product was made by [DOGS](https://wearedogs.net).*
