// tests/test_runner.c
#include "system.h"

void power_test();
void thermal_test();
void net_test();

void run_tests() {
    log_event("TEST", "Running tests");
    power_test();
    thermal_test();
    net_test();
    log_event("TEST", "Tests finished");
}