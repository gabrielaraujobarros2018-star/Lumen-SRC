#include <wf_con.h>

static int link_up = 0;

void wf_link_update(void) {
    link_up = hw_wifi_link_status();
}

int wf_link_state(void) {
    return link_up;
}