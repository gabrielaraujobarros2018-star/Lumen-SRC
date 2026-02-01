#include <stdint.h>

static uint32_t cache_hits = 0;

void fetch_cache_hit(void) {
    cache_hits++;
}

uint32_t fetch_cache_count(void) {
    return cache_hits;
}

void fetch_cache_clear(void) {
    cache_hits = 0;
}