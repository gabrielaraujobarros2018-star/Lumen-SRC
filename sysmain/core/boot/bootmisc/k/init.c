#include "init.h"
#include "panic.h"

void init_cpu(void) {
    /* CPU already validated by contract */
}

void init_memory(const struct boot_info *boot) {
    if (!boot || !boot->memory_map_ptr)
        panic(0x10);
}

void init_allocator(void) {
    /* intentionally stubbed for SP1 */
}

void init_platform(uint32_t boot_path) {
    /* no probing */
    if (boot_path == 0)
        panic(0x11);
}

void init_services(void) {
    /* none enabled in SP1 */
}

void init_idle(void) {
    for (;;) {
#if defined(__x86_64__)
        __asm__ volatile ("hlt");
#elif defined(__aarch64__)
        __asm__ volatile ("wfi");
#endif
    }
}