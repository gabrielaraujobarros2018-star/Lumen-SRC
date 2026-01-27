#include "storage.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void storage_init(void) {
    DIR *d = opendir("/sys/block");
    if (!d) {
        printf("[HAL][STORAGE] failed to open /sys/block\n");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(d))) {
        if (ent->d_name[0] == '.') continue;

        if (strncmp(ent->d_name, "mmc", 3) == 0 ||
            strncmp(ent->d_name, "nvme", 4) == 0 ||
            strncmp(ent->d_name, "sd", 2) == 0) {
            printf("[HAL][STORAGE] detected block device: %s\n", ent->d_name);
        }
    }
    closedir(d);
}