#include <stdio.h>

void command_dispatch(const char *cmd) {
    printf("Command executed: %s\n", cmd);
}

void command_dispatch_init(void) {
    printf("Command dispatcher online\n");
}