#include <stdint.h>

enum bt_audio_state {
    BT_AUDIO_IDLE,
    BT_AUDIO_STREAMING
};

static enum bt_audio_state state = BT_AUDIO_IDLE;

void bt_audio_start(void) {
    state = BT_AUDIO_STREAMING;
}

void bt_audio_stop(void) {
    state = BT_AUDIO_IDLE;
}

int bt_audio_active(void) {
    return state == BT_AUDIO_STREAMING;
}