#include <stdio.h>

void shell_output(const char *msg) {
    printf("[shell] %s\n", msg);
}

void shell_bridge_init(void) {
    shell_output("Shell bridge ready");
}