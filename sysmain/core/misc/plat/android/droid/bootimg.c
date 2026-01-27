#include "bootimg.h"
#include "../earlylog.h"
#include <string.h>

static int validate_magic(const uint8_t *magic) {
    return memcmp(magic, ANDROID_BOOT_MAGIC, ANDROID_BOOT_MAGIC_SIZE) == 0;
}

int bootimg_parse(const void *image, size_t size, struct bootimg_view *out) {
    if (!image || !out || size < sizeof(struct android_boot_header_v3)) {
        earlylog("bootimg: invalid arguments");
        return -1;
    }

    const struct android_boot_header_v3 *hdr = image;

    if (!validate_magic(hdr->magic)) {
        earlylog("bootimg: bad magic");
        return -2;
    }

    if (hdr->header_size < sizeof(*hdr)) {
        earlylog("bootimg: header too small");
        return -3;
    }

    size_t off = hdr->header_size;
    if (off + hdr->kernel_size > size) {
        earlylog("bootimg: kernel overflow");
        return -4;
    }

    out->kernel = (const uint8_t *)image + off;
    out->kernel_size = hdr->kernel_size;
    off += hdr->kernel_size;

    if (off + hdr->ramdisk_size > size) {
        earlylog("bootimg: ramdisk overflow");
        return -5;
    }

    out->ramdisk = (const uint8_t *)image + off;
    out->ramdisk_size = hdr->ramdisk_size;
    out->cmdline = NULL;

    earlylog("bootimg: parsed successfully");
    return 0;
}