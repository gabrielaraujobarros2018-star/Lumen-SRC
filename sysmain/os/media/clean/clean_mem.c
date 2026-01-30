#include <stdint.h>

void mem_zero(void *ptr, uint32_t size) {
    volatile uint8_t *p = ptr;
    for (uint32_t i = 0; i < size; i++)
        p[i] = 0;
}

void mem_scrub(void *ptr, uint32_t size) {
    mem_zero(ptr, size);
}