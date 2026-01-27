#include <stdint.h>

static int tmp_locked = 0;

void tmp_lock(void) {
    tmp_locked = 1;
}

void tmp_unlock(void) {
    tmp_locked = 0;
}

int tmp_is_locked(void) {
    return tmp_locked;
}