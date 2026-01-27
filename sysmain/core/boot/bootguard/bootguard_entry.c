#include <stdint.h>
#include "bootguard.h"

/* Kernel entry symbol (provided by kernel, unchanged) */
extern void kernel_entry(
    uint64_t magic,
    void *boot_info
);

__attribute__((noreturn))
void bootguard_entry(uint64_t sp, struct boot_info *info) {
    if (!info)
        bootguard_fail(0x01);

    bootguard_verify_stack(sp);
    bootguard_verify_memory(info);
    bootguard_verify_bss();

    ((kernel_entry_t)kernel_entry)(
        PALISADE_KERNEL_MAGIC,
        info
    );

    __builtin_unreachable();
}