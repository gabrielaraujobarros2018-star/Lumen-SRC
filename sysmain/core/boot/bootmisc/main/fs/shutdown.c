#include "shutdown.h"
#include "mount.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/reboot.h>

void fs_prepare_shutdown(void) {
    printf("[FS] syncing filesystems\n");
    sync();
    sync();

    fs_remount_ro();

    printf("[FS] filesystem clean for shutdown\n");
}