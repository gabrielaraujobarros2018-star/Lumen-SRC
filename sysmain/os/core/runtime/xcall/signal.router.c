#include <stdio.h>

static int routed_signals = 0;

void signal_route(const char *src, const char *dst) {
    printf("Signal routed: %s -> %s\n", src, dst);
    routed_signals++;
}

void signal_router_init(void) {
    signal_route("kernel", "runtime");
    signal_route("watchdog", "recovery");
}

int signal_router_count(void) {
    return routed_signals;
}