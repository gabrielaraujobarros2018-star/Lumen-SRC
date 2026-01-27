#include <stdint.h>

static int unlocked = 0;

void secret_unlock(void) {
    unlocked = 1;
}

int secret_is_unlocked(void) {
    return unlocked;
}

void secret_reset(void) {
    unlocked = 0;
}