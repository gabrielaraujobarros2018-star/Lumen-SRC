#include "../boot/boot_abi.h"
#include "../earlylog.h"

extern void palisade_kernel_entry(
    const struct palisade_boot_info *
);

void android_enter_kernel(
    const void *kernel_entry,
    const void *dtb
) {
    struct palisade_boot_info info;

    info.abi_version = PALISADE_BOOT_ABI_VERSION;
    info.arch = 0xAA64;
    info.kernel_phys_base = (uint64_t)kernel_entry;
    info.dtb = dtb;
    info.dtb_size = 0;
    info.memmap = 0;
    info.memmap_entries = 0;
    info.early_log = earlylog;

    ((palisade_kernel_entry_t)kernel_entry)(&info);
}