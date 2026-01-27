#include <stdint.h>

static uint64_t sim_imsi = 0;

void sim_set_imsi(uint64_t imsi) {
    sim_imsi = imsi;
}

uint64_t sim_get_imsi(void) {
    return sim_imsi;
}