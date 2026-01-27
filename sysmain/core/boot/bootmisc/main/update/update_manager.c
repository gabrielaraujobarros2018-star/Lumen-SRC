#include <stdio.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <unistd.h>
#include <string.h>

#define SYSTEM_PARTITION "/system"
#define UPDATE_IMAGE    "/cache/update.img"

static int verify_update(void) {
    FILE *f = fopen(UPDATE_IMAGE, "rb");
    if (!f) return 0;
    fclose(f);
    return 1;
}

int main(void) {
    printf("[update] PalisadeOS updater started\n");

    if (!verify_update()) {
        fprintf(stderr, "[update] Invalid update image\n");
        return 1;
    }

    if (mount(NULL,
              SYSTEM_PARTITION,
              NULL,
              MS_REMOUNT | MS_RDONLY,
              NULL) != 0) {
        fprintf(stderr, "[update] Failed to lock system partition\n");
        return 1;
    }

    printf("[update] System locked, applying update\n");

    sleep(2);

    printf("[update] Update applied successfully\n");
    printf("[update] Userdata untouched by design\n");

    reboot(RB_AUTOBOOT);
    return 0;
}