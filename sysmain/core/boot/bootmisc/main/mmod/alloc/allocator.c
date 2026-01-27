#include <stddef.h>
#include <stdint.h>

static uint8_t heap[1024 * 64];
static size_t offset = 0;

void *kmalloc(size_t sz) {
    if (offset + sz > sizeof(heap)) return 0;
    void *p = &heap[offset];
    offset += sz;
    return p;
}