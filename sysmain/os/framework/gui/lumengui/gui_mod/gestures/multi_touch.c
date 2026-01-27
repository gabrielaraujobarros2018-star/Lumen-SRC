#include <gesture.h>

void multi_touch_update(void) {
    if (touch_count() == 2)
        emit_gesture(GESTURE_PINCH);
    else if (touch_count() == 3)
        emit_gesture(GESTURE_THREE_FINGER);
}