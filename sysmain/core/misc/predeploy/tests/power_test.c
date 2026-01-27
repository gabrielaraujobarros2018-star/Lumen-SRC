// tests/power_test.c
#include "power.h"
#include "system.h"

void power_test() {
    power_set_idle(0);
    if (power_is_idle())
        log_event("TEST", "Power idle test failed");
    else
        log_event("TEST", "Power idle test passed");
}