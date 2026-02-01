#include <stdio.h>

int user_syscall(int id) {
    printf("Userspace syscall request: %d\n", id);
    return id;
}

void userspace_wrap_init(void) {
    printf("Userspace wrapper initialized\n");
}