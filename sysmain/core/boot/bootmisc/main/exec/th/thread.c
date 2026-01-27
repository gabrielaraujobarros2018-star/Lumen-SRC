#include <stdint.h>

static uint32_t next_tid = 1;

uint32_t thread_create(void) {
    return next_tid++;
}