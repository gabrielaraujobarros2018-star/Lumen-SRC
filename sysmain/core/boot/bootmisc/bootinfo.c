#include <boot.h>

static struct boot_info info;

void bootinfo_set(enum bootloader_type type,
                  enum boot_mode mode,
                  enum device_class dev) {
    info.loader = type;
    info.mode = mode;
    info.device = dev;
}

const struct boot_info *bootinfo_get(void) {
    return &info;
}

const char *bootloader_name(void) {
    switch (info.loader) {
        case BOOTLOADER_UEFI: return "UEFI";
        case BOOTLOADER_ANDROID: return "Android Bootloader";
        default: return "Unknown";
    }
}