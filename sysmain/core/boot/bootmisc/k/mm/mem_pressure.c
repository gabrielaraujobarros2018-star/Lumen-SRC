#include <memory.h>

static void (*pressure_cb)(int level);

void mem_pressure_register(void (*cb)(int)) {
    pressure_cb = cb;
}

void mem_pressure_check(void) {
    unsigned long total, free;
    page_stats(&total, &free);

    if (!pressure_cb) return;

    if (free < total / 10)
        pressure_cb(MEM_PRESSURE_HIGH);
    else if (free < total / 4)
        pressure_cb(MEM_PRESSURE_MEDIUM);
}