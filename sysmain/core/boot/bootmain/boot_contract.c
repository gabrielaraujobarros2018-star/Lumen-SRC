#include <stdint.h>
#include "boot_abi.h"

#define ARCH_X86_64 0x8664
#define ARCH_ARM64  0xAA64

static void panic(const char *msg) {
    volatile const char *p = msg;
    while (*p) p++;
    for (;;) { }
}

int boot_contract_validate(const struct palisade_boot_info *info) {
    if (!info)
        panic("boot: null boot info");

    if (info->abi_version != PALISADE_BOOT_ABI_VERSION)
        panic("boot: ABI version mismatch");

    if (info->arch != ARCH_X86_64 && info->arch != ARCH_ARM64)
        panic("boot: unsupported architecture");

    if (!info->early_log)
        panic("boot: early logging missing");

    if (!info->dtb && info->arch == ARCH_ARM64)
        panic("boot: ARM64 requires DTB");

    if (info->memmap_entries == 0)
        panic("boot: empty memory map");

    return 0;
}