#include <stdint.h>

static void (*log_fn)(const char *);

void panic_init(void (*logger)(const char *)) {
    log_fn = logger;
}

__attribute__((noreturn))
void kernel_panic(const char *reason) {
    if (log_fn)
        log_fn(reason);

    for (;;)
        asm volatile("hlt");
}