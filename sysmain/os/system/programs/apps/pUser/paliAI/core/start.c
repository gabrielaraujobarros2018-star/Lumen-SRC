#include <stdint.h>

/*
 * PalisadeOS system program entry point.
 * No libc, no CRT, no arguments.
 */

extern int main(void);

__attribute__((noreturn))
void _start(void)
{
    int ret = main();

    /* If main returns, halt deterministically */
    (void)ret;

    for (;;) {
        __asm__ volatile ("wfe");
    }
}