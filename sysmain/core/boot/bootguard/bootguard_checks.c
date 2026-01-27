#include "bootguard.h"

void bootguard_verify_stack(uint64_t sp) {
    if (sp == 0)
        bootguard_fail(0x10);

    if ((sp & 0xF) != 0)
        bootguard_fail(0x11);
}

void bootguard_verify_memory(struct boot_info *info) {
    if (info->mem_size < (16 * 1024 * 1024))
        bootguard_fail(0x20);

    if (info->stack_top < info->mem_base)
        bootguard_fail(0x21);
}

void bootguard_verify_bss(void) {
    extern uint8_t __bss_start[];
    extern uint8_t __bss_end[];

    for (uint8_t *p = __bss_start; p < __bss_end; p++) {
        if (*p != 0)
            bootguard_fail(0x30);
    }
}