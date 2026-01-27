#include <stdint.h>

static uint64_t master_key = 0;

void keystore_set(uint64_t k) {
    master_key = k;
}

uint64_t keystore_get(void) {
    return master_key;
}