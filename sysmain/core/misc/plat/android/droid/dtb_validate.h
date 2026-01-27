#pragma once
#include <stdint.h>

struct dtb_info {
    uint64_t ram_base;
    uint64_t ram_size;
    uint32_t gic_version;
};

int dtb_validate(const void *dtb, struct dtb_info *info);