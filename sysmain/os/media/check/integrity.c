#include <stdint.h>

static uint32_t integrity_flags = 0;

void integrity_mark(uint32_t f) {
    integrity_flags |= f;
}

int integrity_ok(void) {
    return integrity_flags == 0;
}

void integrity_clear(void) {
    integrity_flags = 0;
}

uint32_t integrity_get(void) {
    return integrity_flags;
}