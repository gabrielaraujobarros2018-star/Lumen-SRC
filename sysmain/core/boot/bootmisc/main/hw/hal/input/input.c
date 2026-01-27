#include "input.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void input_init(void) {
    DIR *d = opendir("/dev/input");
    if (!d) {
        printf("[HAL][INPUT] /dev/input missing\n");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(d))) {
        if (strncmp(ent->d_name, "event", 5) == 0) {
            printf("[HAL][INPUT] evdev device: %s\n", ent->d_name);
        }
    }
    closedir(d);
}