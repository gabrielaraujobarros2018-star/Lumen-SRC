#pragma once
#include <stdint.h>

enum mem_region_type {
    MEM_FIRMWARE = 0,
    MEM_KERNEL,
    MEM_STACK,
    MEM_HEAP,
    MEM_MMIO
};

struct mem_region {
    uint64_t base;
    uint64_t size;
    uint32_t type;
};

struct memory_map {
    uint32_t region_count;
    struct mem_region regions[8]; /* fixed, inspectable */
};