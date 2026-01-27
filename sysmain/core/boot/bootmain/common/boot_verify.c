#include "../include/boot.h"

void boot_verify_context(struct boot_context *ctx) {
    if (!ctx) {
        boot_log("BOOT VERIFY FAIL: ctx null");
        for (;;) {}
    }

    if (ctx->stage != BOOT_STAGE_STUB) {
        boot_log("BOOT VERIFY FAIL: wrong stage");
        for (;;) {}
    }

    if (ctx->target != BOOT_X86_64_UEFI &&
        ctx->target != BOOT_ARM64_ANDROID) {
        boot_log("BOOT VERIFY FAIL: unknown target");
        for (;;) {}
    }

    boot_log("BOOT VERIFY OK");
}