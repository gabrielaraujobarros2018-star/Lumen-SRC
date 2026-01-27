#include <memory.h>
#include <boot.h>

int proc_read_bootinfo(char *out, int max) {
    const struct boot_info *bi = bootinfo_get();
    int written = 0;

    written += snprintf(out + written, max,
        "bootloader=%s\n", bootloader_name());

    written += snprintf(out + written, max,
        "mode=%d\n", bi->mode);

    written += snprintf(out + written, max,
        "device_class=%d\n", bi->device);

    return written;
}