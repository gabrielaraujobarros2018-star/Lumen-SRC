#include <stdint.h>
#include "../include/boot.h"

static enum boot_stage current_stage = BOOT_STAGE_FIRMWARE;
static uint64_t boot_ticks = 0;

void boot_set_stage(enum boot_stage s) {
    current_stage = s;
    boot_ticks++;
}

enum boot_stage boot_get_stage(void) {
    return current_stage;
}

uint64_t boot_uptime_ticks(void) {
    return boot_ticks;
}

void boot_state_reset(void) {
    current_stage = BOOT_STAGE_FIRMWARE;
    boot_ticks = 0;
}