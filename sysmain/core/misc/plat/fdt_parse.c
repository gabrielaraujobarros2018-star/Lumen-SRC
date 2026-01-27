#include <stdint.h>

#define FDT_MAGIC 0xd00dfeed
#define FDT_BEGIN_NODE 1
#define FDT_END_NODE   2
#define FDT_PROP       3
#define FDT_END        9

struct fdt_header {
    uint32_t magic;
    uint32_t totalsize;
    uint32_t off_dt_struct;
    uint32_t off_dt_strings;
};

static uint32_t be32(uint32_t v) {
    return __builtin_bswap32(v);
}

int fdt_is_valid(const void *dtb) {
    const struct fdt_header *h = dtb;
    return be32(h->magic) == FDT_MAGIC;
}

const void *fdt_struct_block(const void *dtb) {
    const struct fdt_header *h = dtb;
    return (const uint8_t *)dtb + be32(h->off_dt_struct);
}