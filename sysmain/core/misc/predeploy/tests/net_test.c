// tests/net_test.c
#include "net.h"
#include "system.h"

void net_test() {
    if (net_is_up())
        log_event("TEST", "Network ready");
    else
        log_event("TEST", "Network not initialized");
}