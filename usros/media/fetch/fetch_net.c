#include <stdint.h>

static int net_ready = 0;

void fetch_net_init(void) {
    net_ready = 1;
}

int fetch_net_ready(void) {
    return net_ready;
}

void fetch_net_shutdown(void) {
    net_ready = 0;
}