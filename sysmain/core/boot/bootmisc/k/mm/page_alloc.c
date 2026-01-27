#include <memory.h>

static unsigned long pages_total;
static unsigned long pages_free;

void page_alloc_init(unsigned long total) {
    pages_total = total;
    pages_free = total;
}

void *page_alloc(void) {
    if (pages_free == 0)
        return NULL;

    pages_free--;
    return phys_alloc_page();
}

void page_free(void *page) {
    phys_free_page(page);
    pages_free++;
}

void page_stats(unsigned long *total, unsigned long *free) {
    *total = pages_total;
    *free = pages_free;
}