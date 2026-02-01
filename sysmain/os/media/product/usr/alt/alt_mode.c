#include <stdint.h>

static int alt_mode_enabled = 0;

void alt_enable(void) {
    alt_mode_enabled = 1;
}

void alt_disable(void) {
    alt_mode_enabled = 0;
}

int alt_is_enabled(void) {
    return alt_mode_enabled;
}

void alt_toggle(void) {
    if (alt_mode_enabled)
        alt_disable();
    else
        alt_enable();
}

void alt_init(void) {
    alt_mode_enabled = 0;
}

void alt_tick(void) {
    if (!alt_mode_enabled)
        return;
}

void alt_shutdown(void) {
    alt_mode_enabled = 0;
}