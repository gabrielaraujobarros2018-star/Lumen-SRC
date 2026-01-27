#include <stdint.h>

static int pulse_initialized = 0;

int pulse_init(void) {
    pulse_initialized = 1;
    return 0;
}

int pulse_is_ready(void) {
    return pulse_initialized;
}