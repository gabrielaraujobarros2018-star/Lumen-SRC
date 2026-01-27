#include <stdint.h>

static uint32_t extern_map[16];

void extern_map_set(int i, uint32_t v) {
    extern_map[i] = v;
}

uint32_t extern_map_get(int i) {
    return extern_map[i];
}

void extern_map_clear(void) {
    for (int i = 0; i < 16; i++)
        extern_map[i] = 0;
}