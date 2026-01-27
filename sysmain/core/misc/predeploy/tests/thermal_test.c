// tests/thermal_test.c
#include "power.h"
#include "system.h"

void thermal_test() {
    thermal_update(50.0f);

    if (power_is_idle())
        log_event("TEST", "Thermal throttling OK");
    else
        log_event("TEST", "Thermal throttling FAILED");
}