#include <stddef.h>
#include <stdint.h>

#define HEAP_SIZE (64 * 1024)

static uint8_t heap[HEAP_SIZE];
static size_t heap_offset = 0;

void* palisade_alloc(size_t size) {
    if (size == 0) return NULL;
    if (heap_offset + size > HEAP_SIZE) return NULL;

    void* ptr = &heap[heap_offset];
    heap_offset += (size + 7) & ~7; /* 8-byte align */
    return ptr;
}

void palisade_free(void* ptr) {
    /* no-op: bump allocator */
    (void)ptr;
}