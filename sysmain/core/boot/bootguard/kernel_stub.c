#include <stdint.h>

/*
 * Weak stub for kernel entry.
 * Replaced automatically when real kernel is linked.
 */
__attribute__((weak))
void kernel_entry(uint64_t magic, void *boot_info) {
    (void)magic;
    (void)boot_info;

    for (;;) {
        __asm__ volatile ("wfe");
    }
}