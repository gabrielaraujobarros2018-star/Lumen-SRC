#include <stdint.h>

enum audio_sink {
    SINK_SPEAKER,
    SINK_HEADPHONES
};

static enum audio_sink current_sink = SINK_SPEAKER;

void audio_route(enum audio_sink sink) {
    current_sink = sink;
}

enum audio_sink audio_current_sink(void) {
    return current_sink;
}