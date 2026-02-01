#include <stdint.h>

static int touch_active = 0;

void touch_down(void) {
    touch_active = 1;
}

void touch_up(void) {
    touch_active = 0;
}

int touch_is_active(void) {
    return touch_active;
}

void touch_init(void) {
    touch_active = 0;
}