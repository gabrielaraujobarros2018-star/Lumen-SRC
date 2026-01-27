#include <gesture.h>

void edge_swipe_update(void) {
    if (touch_x() < 5 && touch_dx() > 30) {
        emit_gesture(GESTURE_BACK);
    }
}