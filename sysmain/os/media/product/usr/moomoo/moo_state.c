#include <stdint.h>

static int moo_state = 0;

void moo_set(int v) {
    moo_state = v;
}

int moo_get(void) {
    return moo_state;
}

void moo_reset(void) {
    moo_state = 0;
}