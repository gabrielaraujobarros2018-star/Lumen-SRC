#include <stdint.h>

static uint32_t caps = 0;

void cap_grant(uint32_t c) {
    caps |= c;
}

int cap_has(uint32_t c) {
    return (caps & c) != 0;
}