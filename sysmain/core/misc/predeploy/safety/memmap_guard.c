#include <stdint.h>

struct mem_region {
    uint64_t base;
    uint64_t size;
    uint32_t type;
};

int memmap_validate(
    const struct mem_region *map,
    uint32_t count
) {
    if (!map || count == 0)
        return -1;

    for (uint32_t i = 0; i < count; i++) {
        if (map[i].size == 0)
            return -1;
        if (map[i].base & 0xFFF)
            return -1;
    }
    return 0;
}