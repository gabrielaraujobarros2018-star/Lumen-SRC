#include <stdint.h>

extern void arch_halt(void);
extern void early_log(const char *msg);

__attribute__((noreturn))
void kernel_panic(const char *reason) {
    if (reason) {
        early_log("KERNEL PANIC: ");
        early_log(reason);
        early_log("\n");
    } else {
        early_log("KERNEL PANIC: unknown\n");
    }

    for (;;) {
        arch_halt();
    }
}