#include <stdio.h>

int permission_check(const char *proc) {
    printf("Permission check: %s\n", proc);
    return 1;
}

void permission_gate_init(void) {
    printf("Permission gate ready\n");
}