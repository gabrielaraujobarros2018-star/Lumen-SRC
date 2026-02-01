#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int autostart;
} svc_entry;

static svc_entry services[32];
static int svc_count = 0;

void svc_register(const char *name, int autostart) {
    if (svc_count >= 32) return;
    strncpy(services[svc_count].name, name, 63);
    services[svc_count].autostart = autostart;
    svc_count++;
}

void svc_loader_init(void) {
    svc_register("ipc", 1);
    svc_register("shell", 1);
    svc_register("gui", 0);
}

void svc_loader_start(void) {
    for (int i = 0; i < svc_count; i++) {
        if (services[i].autostart) {
            printf("Starting service: %s\n", services[i].name);
        }
    }
}