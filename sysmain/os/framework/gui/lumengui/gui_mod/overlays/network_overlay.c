#include <overlay.h>

static unsigned long last_tx = 0;
static unsigned long last_rx = 0;

void network_overlay_update(void) {
    last_tx = net_tx_bytes();
    last_rx = net_rx_bytes();
}

void network_overlay_render(void) {
    char buf[64];
    snprintf(buf, sizeof(buf), "TX:%lu RX:%lu", last_tx, last_rx);
    draw_text(buf, 10, 65);
}