#include <stdint.h>

static uint32_t ticks = 0;

uint32_t scheduler_yield(void) {
    ticks++;
    return ticks;
}

uint32_t scheduler_ticks(void) {
    return ticks;
}

void scheduler_reset(void) {
    ticks = 0;
}