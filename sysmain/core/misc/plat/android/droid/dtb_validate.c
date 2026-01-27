#include "dtb_validate.h"
#include "../earlylog.h"

#define FDT_MAGIC 0xd00dfeed

struct fdt_header {
    uint32_t magic;
    uint32_t totalsize;
    uint32_t off_dt_struct;
    uint32_t off_dt_strings;
    uint32_t off_mem_rsvmap;
};

static uint32_t be32(uint32_t v) {
    return __builtin_bswap32(v);
}

int dtb_validate(const void *dtb, struct dtb_info *info) {
    if (!dtb || !info) {
        earlylog("dtb: null pointer");
        return -1;
    }

    const struct fdt_header *hdr = dtb;
    if (be32(hdr->magic) != FDT_MAGIC) {
        earlylog("dtb: bad magic");
        return -2;
    }

    /* Minimal conservative defaults */
    info->ram_base = 0;
    info->ram_size = 0;
    info->gic_version = 3;

    earlylog("dtb: validated header");
    return 0;
}