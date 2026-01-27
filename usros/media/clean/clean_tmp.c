#include <stdint.h>

static uint32_t tmp_objects = 0;

void tmp_add(void) {
    tmp_objects++;
}

void tmp_clear(void) {
    tmp_objects = 0;
}

uint32_t tmp_count(void) {
    return tmp_objects;
}

void tmp_init(void) {
    tmp_objects = 0;
}