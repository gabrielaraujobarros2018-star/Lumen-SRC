#include <stdio.h>

int syscall_dispatch(int id) {
    printf("Syscall invoked: %d\n", id);
    return 0;
}

void syscall_gate_init(void) {
    printf("Syscall gate ready\n");
}