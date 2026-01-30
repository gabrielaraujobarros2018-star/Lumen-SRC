#include <stdint.h>

extern void serial_write(const char *);

void alt_debug_log(const char *msg) {
    serial_write("[ALT] ");
    serial_write(msg);
    serial_write("\n");
}

void alt_debug_state(uint32_t state) {
    (void)state;
}

void alt_debug_init(void) {
    alt_debug_log("initialized");
}