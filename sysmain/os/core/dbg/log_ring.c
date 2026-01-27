#include <log.h>

#define LOG_RING_SZ 4096

static char ring[LOG_RING_SZ];
static unsigned int head = 0;

void log_ring_write(const char *msg) {
    while (*msg) {
        ring[head++ % LOG_RING_SZ] = *msg++;
    }
}

void log_ring_dump(char *out, int max) {
    for (int i = 0; i < max && i < LOG_RING_SZ; i++)
        out[i] = ring[i];
}