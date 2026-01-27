#include <stdio.h>

static const char *services[16];
static int count = 0;

void service_register(const char *name) {
    services[count++] = name;
    printf("Service registered: %s\n", name);
}

void service_registry_init(void) {
    service_register("ipc");
    service_register("watchdog");
}