#pragma once
#include <stdint.h>
#include <stddef.h>

#define ANDROID_BOOT_MAGIC "ANDROID!"
#define ANDROID_BOOT_MAGIC_SIZE 8

struct android_boot_header_v3 {
    uint8_t  magic[8];
    uint32_t kernel_size;
    uint32_t ramdisk_size;
    uint32_t os_version;
    uint32_t header_size;
    uint32_t reserved[4];
};

struct android_boot_header_v4 {
    struct android_boot_header_v3 v3;
    uint32_t signature_size;
};

struct bootimg_view {
    const void *kernel;
    size_t kernel_size;
    const void *ramdisk;
    size_t ramdisk_size;
    const char *cmdline;
};

int bootimg_parse(const void *image, size_t size, struct bootimg_view *out);