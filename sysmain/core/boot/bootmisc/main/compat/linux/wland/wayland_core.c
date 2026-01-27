#include <stdint.h>

struct wl_display {
    uint32_t clients;
};

static struct wl_display display = {0};

void wl_register_client(void) {
    display.clients++;
}

uint32_t wl_client_count(void) {
    return display.clients;
}