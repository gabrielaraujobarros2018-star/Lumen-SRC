#pragma once
#include <stdint.h>

typedef enum {
    FS_EXT4,
    FS_F2FS
} fs_type_t;

void fs_init(void);
fs_type_t fs_detect_root(void);