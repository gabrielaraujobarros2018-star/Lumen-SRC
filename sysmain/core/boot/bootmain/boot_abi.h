#pragma once
#include <stdint.h>

#define PALISADE_BOOT_ABI_VERSION 1

struct boot_mem_region {
    uint64_t base;
    uint64_t size;
    uint32_t type;
};

struct palisade_boot_info {
    uint32_t abi_version;
    uint32_t arch;
    uint64_t kernel_phys_base;

    const void *dtb;
    uint64_t dtb_size;

    struct boot_mem_region *memmap;
    uint32_t memmap_entries;

    void (*early_log)(const char *);
};

typedef void (*palisade_kernel_entry_t)(
    const struct palisade_boot_info *info
);