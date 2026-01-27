#include <stdint.h>

static int accel = 0;

void motion_sensor_update(int v) {
    accel = v;
}

int motion_sensor_get(void) {
    return accel;
}