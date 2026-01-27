#include <stdint.h>

__attribute__((noreturn))
void bootguard_fail(uint32_t reason) {
    volatile uint32_t *fail_code =
        (volatile uint32_t *)0x50000000;

    *fail_code = reason;

    for (;;) {
        __asm__ volatile ("wfe");
    }
}