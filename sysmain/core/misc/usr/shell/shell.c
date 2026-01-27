#include "../include/userland.h"

int shell_main(void) {
    const char *banner = "PalisadeOS shell\n";
    sys_write(1, banner, 18);

    while (1) {
        const char *prompt = "> ";
        sys_write(1, prompt, 2);

        scheduler_yield();
    }

    return 0;
}