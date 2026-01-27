#include "boot_abi.h"

extern void kernel_main(const struct palisade_boot_info *);

static int early_arch_done;

void arch_early_complete(void) {
    early_arch_done = 1;
}

void enter_common_init(const struct palisade_boot_info *info) {
    if (!early_arch_done) {
        info->early_log("init: arch bring-up incomplete");
        for (;;);
    }

    kernel_main(info);
}