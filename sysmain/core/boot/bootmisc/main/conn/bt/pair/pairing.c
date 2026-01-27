#include <stdint.h>

static uint32_t paired_devices = 0;

void bt_pair_device(void) {
    paired_devices++;
}

uint32_t bt_paired_count(void) {
    return paired_devices;
}