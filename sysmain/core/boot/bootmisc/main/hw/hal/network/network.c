#include "network.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void network_init(void) {
    DIR *d = opendir("/sys/class/net");
    if (!d) {
        printf("[HAL][NET] failed to open /sys/class/net\n");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(d))) {
        if (ent->d_name[0] == '.') continue;

        if (strcmp(ent->d_name, "lo") != 0) {
            printf("[HAL][NET] interface: %s\n", ent->d_name);
        }
    }
    closedir(d);
}