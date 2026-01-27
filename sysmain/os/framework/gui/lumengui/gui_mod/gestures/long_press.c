#include <gesture.h>

static float press_time = 0;

void long_press_update(void) {
    if (touch_down()) {
        press_time += frame_delta();
        if (press_time > 0.6f)
            emit_gesture(GESTURE_LONG_PRESS);
    } else {
        press_time = 0;
    }
}