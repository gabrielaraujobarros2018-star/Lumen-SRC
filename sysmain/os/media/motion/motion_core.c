#include <stdint.h>

static int moving = 0;

void motion_start(void) {
    moving = 1;
}

void motion_stop(void) {
    moving = 0;
}

int motion_active(void) {
    return moving;
}