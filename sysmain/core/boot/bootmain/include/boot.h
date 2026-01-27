#pragma once
#include <stdint.h>

enum boot_target {
    BOOT_X86_64_UEFI,
    BOOT_ARM64_ANDROID
};

enum boot_stage {
    BOOT_STAGE_FIRMWARE,
    BOOT_STAGE_STUB,
    BOOT_STAGE_KERNEL
};

struct boot_context {
    enum boot_target target;
    enum boot_stage stage;
    uint64_t timestamp;
    void *handoff_data;
};

void boot_log(const char *msg);
void boot_set_stage(enum boot_stage s);
enum boot_stage boot_get_stage(void);
void boot_verify_context(struct boot_context *ctx);