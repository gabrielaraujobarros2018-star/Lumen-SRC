#include <stdint.h>

int motion_filter(int v) {
    if (v < 0) return 0;
    return v;
}

void motion_filter_init(void) {
}