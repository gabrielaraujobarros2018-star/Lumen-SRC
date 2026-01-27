#include <stdio.h>

static int state_version = 0;

void state_sync_tick(void) {
    state_version++;
}

int state_sync_version(void) {
    return state_version;
}

void state_sync_init(void) {
    state_version = 1;
    printf("State sync initialized\n");
}