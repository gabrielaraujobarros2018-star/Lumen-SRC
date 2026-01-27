#include <stdint.h>

static int lte_online = 0;

void lte_attach(void) {
    lte_online = 1;
}

void lte_detach(void) {
    lte_online = 0;
}

int lte_is_online(void) {
    return lte_online;
}