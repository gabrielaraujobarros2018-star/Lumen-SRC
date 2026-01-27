#include "integrity.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fs_check_integrity(fs_type_t type) {
    pid_t pid = fork();
    if (pid == 0) {
        if (type == FS_EXT4) {
            execl("/sbin/e2fsck", "e2fsck", "-p", "/dev/root", NULL);
        } else {
            execl("/sbin/fsck.f2fs", "fsck.f2fs", "-a", "/dev/root", NULL);
        }
        _exit(1);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        printf("[FS] filesystem check completed\n");
    }
}