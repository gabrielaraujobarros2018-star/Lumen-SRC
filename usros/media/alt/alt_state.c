#include <stdint.h>

static uint32_t alt_state_flags = 0;

void alt_state_set(uint32_t flag) {
    alt_state_flags |= flag;
}

void alt_state_clear(uint32_t flag) {
    alt_state_flags &= ~flag;
}

int alt_state_has(uint32_t flag) {
    return (alt_state_flags & flag) != 0;
}

uint32_t alt_state_get(void) {
    return alt_state_flags;
}

void alt_state_reset(void) {
    alt_state_flags = 0;
}