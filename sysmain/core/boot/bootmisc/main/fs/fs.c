#include "fs.h"
#include "mount.h"
#include "integrity.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static fs_type_t root_fs;

fs_type_t fs_detect_root(void) {
    FILE *f = fopen("/proc/mounts", "r");
    if (!f) return FS_EXT4;

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, " / ")) {
            if (strstr(line, "f2fs")) {
                fclose(f);
                return FS_F2FS;
            }
            if (strstr(line, "ext4")) {
                fclose(f);
                return FS_EXT4;
            }
        }
    }

    fclose(f);
    return FS_EXT4;
}

void fs_init(void) {
    root_fs = fs_detect_root();

    if (root_fs == FS_EXT4)
        printf("[FS] root filesystem: ext4\n");
    else
        printf("[FS] root filesystem: f2fs\n");

    fs_mount_essential();
    fs_check_integrity(root_fs);
}