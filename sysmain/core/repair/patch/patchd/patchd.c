#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static void lock_process() {
    if (setsid() < 0) exit(1);
    signal(SIGTERM, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    signal(SIGKILL, SIG_IGN);
}

static void enforce_root() {
    if (getuid() != 0) {
        fprintf(stderr, "patchd: root required\n");
        exit(1);
    }
}

static void freeze_filesystem() {
    mount(NULL, "/", NULL, MS_REMOUNT | MS_RDONLY, NULL);
    mount(NULL, "/", NULL, MS_REMOUNT, NULL);
}

static void ensure_immutable() {
    system("chattr +i /palisade/patch/patchd/patchd");
    system("chattr +i /palisade/patch/patchd/patch_guard");
}

static void exec_engine() {
    int ret = system("/palisade/patch/engine/patch_engine.sh");
    if (ret != 0) {
        fprintf(stderr, "patchd: engine failed\n");
        sleep(1);
        exec_engine();
    }
}

int main() {
    enforce_root();
    lock_process();
    freeze_filesystem();
    ensure_immutable();

    while (1) {
        exec_engine();
        sleep(5);
    }

    return 0;
}