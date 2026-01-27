#include <stdint.h>

/*
 * Kernel-provided symbols.
 * These are resolved at load time by the PalisadeOS kernel.
 */
extern void system_log(const char *);
extern int framework_init_all(void);
extern int driver_init_all(void);

/*
 * Program-defined entry point.
 * Every program must expose this symbol.
 */
extern int program_main(void);

/*
 * Canonical program entry.
 * Kernel jumps here after loading the ELF.
 */
__attribute__((noreturn))
void _start(void) {
    int ret;

    ret = program_main();
    (void)ret;

    /* Programs are not allowed to return */
    for (;;) {
        __asm__ volatile ("wfe");
    }
}