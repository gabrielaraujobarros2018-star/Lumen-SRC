#include <stdio.h>

static int bridges_ready = 0;

void bridge_map_register(const char *name) {
    printf("Bridge registered: %s\n", name);
    bridges_ready++;
}

void bridge_loader_init(void) {
    bridge_map_register("kernel-ipc");
    bridge_map_register("fs-runtime");
    bridge_map_register("gui-backend");
}

int bridge_loader_ready(void) {
    return bridges_ready >= 2;
}