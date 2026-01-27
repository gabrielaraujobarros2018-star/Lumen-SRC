#pragma once
#include <stdint.h>
#include "boot_contract.h"

enum init_stage {
    INIT_CPU = 0,
    INIT_MEMORY,
    INIT_ALLOCATOR,
    INIT_PLATFORM,
    INIT_SERVICES,
    INIT_IDLE
};

void init_cpu(void);
void init_memory(const struct boot_info *boot);
void init_allocator(void);
void init_platform(uint32_t boot_path);
void init_services(void);
void init_idle(void);