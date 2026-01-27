#include "display.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void display_init(void) {
    if (access("/dev/fb0", F_OK) == 0) {
        printf("[HAL][DISPLAY] framebuffer available (/dev/fb0)\n");
    }

    DIR *d = opendir("/sys/class/drm");
    if (!d) {
        printf("[HAL][DISPLAY] DRM not present\n");
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(d))) {
        if (strstr(ent->d_name, "card")) {
            printf("[HAL][DISPLAY] DRM device: %s\n", ent->d_name);
        }
    }
    closedir(d);
}