#include <stdint.h>

static int extern_locked = 0;

void extern_lock(void) {
    extern_locked = 1;
}

void extern_unlock(void) {
    extern_locked = 0;
}

int extern_is_locked(void) {
    return extern_locked;
}