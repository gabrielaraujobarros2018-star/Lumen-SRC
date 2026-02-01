#include <stdio.h>

void env_sync_apply(void) {
    printf("Environment synced\n");
}

void env_sync_init(void) {
    env_sync_apply();
}