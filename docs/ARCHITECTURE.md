# Fetch — Architecture

## Form factor
VST3 instrument/MIDI-effect built with JUCE. Loads on a MIDI track in
Ableton Live (and any VST3 host). All UI lives in the plugin window.

## Pipeline
1. **Chat UI** (JUCE components) — prompt input, conversation history,
   per-track role selector (melody / bass / chords / drums).
2. **Prompt builder** — system prompt carries session context: host BPM
   (from `AudioPlayHead`), key/scale (user-set or detected), loop length,
   the track's role, and the current note plan (so edits are deltas).
3. **Model backend** — pluggable:
   - Local: LM Studio or Ollama over `http://localhost` (OpenAI-compatible
     chat endpoint). Default. No account, no key, works offline.
   - Cloud: Claude / OpenAI-compatible APIs, key entered by the user.
4. **Note plan** — the model answers in a strict JSON schema:
   `{ bpm, key, scale, bars, tracks: [{ role, notes: [{ pitch, start,
   length, velocity }] }] }`. Schema-validated before anything plays;
   invalid output is re-asked once, then surfaced as an error in the chat.
5. **MIDI renderer** — converts the plan to a looping MIDI sequence,
   sample-accurately scheduled against the host transport in
   `processBlock`. Humanize (timing/velocity jitter) applied at render.
6. **Export** — drag the generated pattern out as a `.mid` file, or record
   the track's output in Live to freeze it into a clip.

## Honest limits (v1)
- A VST cannot create tracks or clips in Live's session, rename things, or
  arrange. Fetch v1 generates MIDI *inside* the track it sits on.
- Model latency: generation happens on a background thread; the current
  loop keeps playing until the new plan is ready, then swaps on the bar.

## Phase 2 — session control
A Max for Live companion device using the Live Object Model
(`live.object` / `live.remote`) bridged to Fetch over localhost:
create tracks, write clips directly, set tempo/key, arrange sections.
That turns prompts into full song skeletons, not just per-track parts.

## Guardrails
- Never blocks the audio thread: all network and JSON work is off-thread.
- Patterns are bounded (max bars, note density caps) so a bad generation
  can't flood a track.
- Nothing leaves the machine in local mode.
