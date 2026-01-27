#include <stdint.h>

uintptr_t kernel_base = 0;

void memory_set_kernel_base(uintptr_t base) {
    kernel_base = base;
}