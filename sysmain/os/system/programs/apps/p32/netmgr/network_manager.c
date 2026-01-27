#include <stdint.h>

static uint8_t network_up = 0;

int network_enable(void) {
    network_up = 1;
    return 0;
}

int network_disable(void) {
    network_up = 0;
    return 0;
}