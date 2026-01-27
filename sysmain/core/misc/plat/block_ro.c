#include <stdint.h>

struct block_device {
    uint64_t sector_size;
    uint64_t sector_count;
    int (*read)(uint64_t lba, void *buf, uint64_t count);
};

static int null_read(uint64_t lba, void *buf, uint64_t count) {
    (void)lba;
    (void)buf;
    (void)count;
    return -1;
}

static struct block_device dev = {
    .sector_size = 512,
    .sector_count = 0,
    .read = null_read
};

struct block_device *block_get(void) {
    return &dev;
}