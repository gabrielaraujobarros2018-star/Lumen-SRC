#include <stdint.h>

extern int init_main(void);

void kernel_launch_init(void) {
    int ret = init_main();
    (void)ret;
    for (;;) { __asm__ volatile("hlt"); }
}