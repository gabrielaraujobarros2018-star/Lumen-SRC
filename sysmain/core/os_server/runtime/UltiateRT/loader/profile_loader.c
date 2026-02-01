#include <stdio.h>
#include <string.h>

static char active_profile[32];

void profile_set(const char *name) {
    strncpy(active_profile, name, 31);
}

const char *profile_get(void) {
    return active_profile;
}

void profile_loader_init(void) {
    profile_set("default");
    printf("Runtime profile loaded: %s\n", active_profile);
}