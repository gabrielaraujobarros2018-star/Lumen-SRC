#include <stdint.h>

static uint32_t tmp_used = 0;

void tmp_alloc(uint32_t s) {
    tmp_used += s;
}

uint32_t tmp_used_bytes(void) {
    return tmp_used;
}

void tmp_alloc_reset(void) {
    tmp_used = 0;
}