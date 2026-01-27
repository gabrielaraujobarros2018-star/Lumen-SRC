#include <stdint.h>

static uint32_t leased_ip = 0;

void dhcp_assign(uint32_t ip) {
    leased_ip = ip;
}

uint32_t dhcp_ip(void) {
    return leased_ip;
}