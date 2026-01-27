#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <errno.h>
#include <string.h>

#define USERDATA_DEVICE "/dev/block/userdata"
#define USERDATA_MOUNT  "/userdata"

static void panic(const char *msg) {
    fprintf(stderr, "INIT PANIC: %s\n", msg);
    exit(1);
}

int main(void) {
    printf("[init] PalisadeOS init starting\n");

    if (mkdir(USERDATA_MOUNT, 0755) == -1 && errno != EEXIST) {
        panic("Failed to create /userdata mount point");
    }

    if (mount(USERDATA_DEVICE,
              USERDATA_MOUNT,
              "ext4",
              MS_RDONLY | MS_NODEV | MS_NOEXEC,
              "") != 0) {
        panic("Userdata mount failed");
    }

    printf("[init] Userdata mounted read-only\n");

    if (access("/userdata", R_OK) != 0) {
        panic("Userdata not accessible");
    }

    printf("[init] Launching system services\n");

    execl("/system/bin/system_server",
          "system_server",
          NULL);

    panic("Failed to launch system_server");
    return 0;
}