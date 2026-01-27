#include <stdint.h>

static uint64_t total_pages = 0;

void phys_register(uint64_t pages) {
    total_pages = pages;
}

uint64_t phys_total(void) {
    return total_pages;
}