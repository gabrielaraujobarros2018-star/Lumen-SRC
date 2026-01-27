#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/inotify.h>
#include <limits.h>
#include <string.h>

#define WATCH_PATH "/palisade/patch"

static void hard_kill(pid_t pid) {
    kill(pid, SIGKILL);
}

int main() {
    int fd = inotify_init();
    if (fd < 0) return 1;

    int wd = inotify_add_watch(
        fd,
        WATCH_PATH,
        IN_DELETE | IN_MODIFY | IN_MOVE | IN_ATTRIB
    );

    char buffer[4096];
    while (1) {
        int length = read(fd, buffer, sizeof(buffer));
        if (length < 0) continue;

        int i = 0;
        while (i < length) {
            struct inotify_event *event =
                (struct inotify_event *) &buffer[i];

            if (event->mask) {
                system("logger PATCH_GUARD: tamper detected");
                system("reboot -f");
            }

            i += sizeof(struct inotify_event) + event->len;
        }
    }

    close(fd);
    return 0;
}