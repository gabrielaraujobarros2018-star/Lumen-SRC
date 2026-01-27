#include <wf_con.h>

static int wf_ready = 0;

int wf_init(void) {
    wf_ready = hw_wifi_probe();
    return wf_ready ? 0 : -1;
}

int wf_is_ready(void) {
    return wf_ready;
}

int wf_connect(const char *ssid) {
    if (!wf_ready) return -1;
    return hw_wifi_connect(ssid);
}