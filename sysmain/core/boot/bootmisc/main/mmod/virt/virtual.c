#include <stdint.h>

static int vm_enabled = 0;

void vm_enable(void) {
    vm_enabled = 1;
}

int vm_is_enabled(void) {
    return vm_enabled;
}