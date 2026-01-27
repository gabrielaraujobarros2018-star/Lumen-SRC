#include <stdint.h>

static int master_volume = 50;

void mixer_set_volume(int v) {
    if (v < 0) v = 0;
    if (v > 100) v = 100;
    master_volume = v;
}

int mixer_volume(void) {
    return master_volume;
}