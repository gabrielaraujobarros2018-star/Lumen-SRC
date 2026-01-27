#include <stdio.h>

void fault_handle(const char *reason) {
    printf("Fault handled: %s\n", reason);
}

void fault_handler_init(void) {
    printf("Fault handler ready\n");
}