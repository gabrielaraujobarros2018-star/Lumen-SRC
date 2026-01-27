#include <wf_con.h>

int wf_scan(struct wf_network *out, int max) {
    if (!wf_is_ready())
        return -1;

    int found = hw_wifi_scan(out, max);
    return found;
}