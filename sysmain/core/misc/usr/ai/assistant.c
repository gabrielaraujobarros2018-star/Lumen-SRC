#include <stdint.h>

static int assistant_online = 0;
static uint32_t queries = 0;

void assistant_start(void) {
    assistant_online = 1;
}

int assistant_active(void) {
    return assistant_online;
}

void assistant_query(const char *q) {
    (void)q;
    if (assistant_online) {
        queries++;
    }
}

uint32_t assistant_query_count(void) {
    return queries;
}