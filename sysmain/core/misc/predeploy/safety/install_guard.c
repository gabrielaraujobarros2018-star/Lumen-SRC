#include <stdint.h>

static int recovery_present;

void recovery_set_available(int present) {
    recovery_present = present;
}

int install_allowed(void) {
    if (!recovery_present)
        return 0;
    return 1;
}