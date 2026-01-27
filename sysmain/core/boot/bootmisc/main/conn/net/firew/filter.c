#include <stdint.h>

int firewall_allow(uint16_t port) {
    if (port == 22 || port == 80 || port == 443)
        return 1;
    return 0;
}