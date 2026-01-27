#include <stdio.h>
#include <stdlib.h>

static void *shared_region = NULL;

void sharedmem_init(size_t size) {
    shared_region = malloc(size);
    if (shared_region)
        printf("Shared memory allocated: %zu bytes\n", size);
}

void *sharedmem_get(void) {
    return shared_region;
}

void sharedmem_release(void) {
    free(shared_region);
    shared_region = NULL;
}