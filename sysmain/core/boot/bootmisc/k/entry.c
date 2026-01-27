#include "boot_contract.h"
#include "init.h"
#include "panic.h"

void kernel_entry(struct boot_info *boot) {
    if (!boot)
        panic(0x01);

    if (boot->contract_version != BOOT_CONTRACT_VERSION)
        panic(0x02);

    init_cpu();                          /* 1 */
    init_memory(boot);                  /* 2 */
    init_allocator();                   /* 3 */
    init_platform(boot->boot_path);     /* 4 */
    init_services();                    /* 5 */
    init_idle();                        /* 6 */
}