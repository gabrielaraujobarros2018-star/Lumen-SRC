#include <stdint.h>

static int system_healthy = 1;

void health_fail(void) {
    system_healthy = 0;
}

void health_restore(void) {
    system_healthy = 1;
}

int health_status(void) {
    return system_healthy;
}

void health_init(void) {
    system_healthy = 1;
}