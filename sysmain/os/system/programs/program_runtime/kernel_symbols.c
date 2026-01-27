#include <stdint.h>

/*
 * Weak kernel symbols.
 * These allow programs to link without the kernel present.
 * The real kernel overrides them at runtime.
 */

__attribute__((weak))
void system_log(const char *msg) {
    (void)msg;
}

__attribute__((weak))
int framework_init_all(void) {
    return -1;
}

__attribute__((weak))
int driver_init_all(void) {
    return -1;
}