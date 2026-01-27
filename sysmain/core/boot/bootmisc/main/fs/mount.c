#include "mount.h"
#include <sys/mount.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

static void ensure_dir(const char *path) {
    if (access(path, F_OK) != 0)
        mkdir(path, 0755);
}

void fs_mount_essential(void) {
    ensure_dir("/proc");
    ensure_dir("/sys");
    ensure_dir("/dev");
    ensure_dir("/data");

    mount("proc", "/proc", "proc", 0, NULL);
    mount("sysfs", "/sys", "sysfs", 0, NULL);
    mount("devtmpfs", "/dev", "devtmpfs", 0, NULL);

    if (mount("/dev/root", "/", NULL, MS_REMOUNT | MS_RDONLY, NULL) == 0)
        printf("[FS] root remounted read-only\n");
}

void fs_remount_rw(void) {
    if (mount(NULL, "/", NULL, MS_REMOUNT, NULL) == 0)
        printf("[FS] root remounted read-write\n");
    else
        perror("[FS] remount rw failed");
}

void fs_remount_ro(void) {
    if (mount(NULL, "/", NULL, MS_REMOUNT | MS_RDONLY, NULL) == 0)
        printf("[FS] root remounted read-only\n");
}