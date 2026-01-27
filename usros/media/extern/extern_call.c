#include <stdint.h>

extern void platform_call(uint32_t id);

void extern_dispatch(uint32_t id) {
    platform_call(id);
}

void extern_init(void) {
}