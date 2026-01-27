#include <stdint.h>

static uint32_t settings_flags = 0;

void settings_set(uint32_t mask) {
    settings_flags |= mask;
}

uint32_t settings_get(void) {
    return settings_flags;
}