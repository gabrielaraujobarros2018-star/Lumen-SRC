#pragma once
#include <stdint.h>

#define BOOT_CONTRACT_VERSION 1

enum boot_path {
    BOOT_UEFI = 1,
    BOOT_LEGACY = 2,
    BOOT_ANDROID = 3
};

struct boot_info {
    uint32_t contract_version;
    uint32_t boot_path;
    uint64_t memory_map_ptr;
    uint64_t memory_map_size;
};