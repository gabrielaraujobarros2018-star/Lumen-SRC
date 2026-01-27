#ifndef PALISADE_BOOTGUARD_H
#define PALISADE_BOOTGUARD_H

#include <stdint.h>

/* Kernel entry signature (LOCKED ABI) */
typedef void (*kernel_entry_t)(
    uint64_t magic,
    void    *boot_info
);

/* Expected magic value */
#define PALISADE_KERNEL_MAGIC 0x50414C49534B4552ULL /* "PALISKER" */

/* Boot info structure passed unchanged to kernel */
struct boot_info {
    uint64_t mem_base;
    uint64_t mem_size;
    uint64_t stack_top;
};

/* Verification stages */
void bootguard_verify_stack(uint64_t sp);
void bootguard_verify_memory(struct boot_info *info);
void bootguard_verify_bss(void);
void bootguard_fail(uint32_t reason);

#endif