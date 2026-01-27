#include <stdint.h>

extern void kernel_main(uintptr_t boot_info);

void firmware_jump_to_kernel(uintptr_t boot_info) {
    kernel_main(boot_info);
    for (;;) { __asm__ volatile("hlt"); }
}