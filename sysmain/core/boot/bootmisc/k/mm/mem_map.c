#include <memory.h>

static struct mem_region regions[64];
static int region_count = 0;

void mem_map_add(uintptr_t base, size_t size, int type) {
    if (region_count >= 64) return;

    regions[region_count].base = base;
    regions[region_count].size = size;
    regions[region_count].type = type;
    region_count++;
}

void mem_map_dump(void) {
    for (int i = 0; i < region_count; i++) {
        klog("MEM: %p - %zu type=%d\n",
             regions[i].base,
             regions[i].size,
             regions[i].type);
    }
}