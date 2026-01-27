#pragma once
#include <stdint.h>

typedef enum {
    PLATFORM_DESKTOP,
    PLATFORM_PHONE
} hal_platform_t;

void hal_init(void);
hal_platform_t hal_platform(void);