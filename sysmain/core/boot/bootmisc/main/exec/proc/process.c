#include <stdint.h>

static uint32_t next_pid = 1;

uint32_t process_create(void) {
    return next_pid++;
}