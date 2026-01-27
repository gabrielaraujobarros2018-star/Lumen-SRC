#include <stdint.h>

static uint32_t settings_loaded = 0;

void settings_load(void) {
    settings_loaded = 1;
}

int settings_ready(void) {
    return settings_loaded;
}

void settings_reset(void) {
    settings_loaded = 0;
}