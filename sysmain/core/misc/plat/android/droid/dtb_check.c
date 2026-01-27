#include <stdint.h>

struct dtb_header {
    uint32_t magic;
    uint32_t size;
};

int dtb_validate(void *dtb) {
    struct dtb_header *h = (struct dtb_header *)dtb;

    if (!dtb) return -1;
    if (h->magic != 0xD00DFEED) return -2;
    if (h->size == 0) return -3;

    return 0;
}