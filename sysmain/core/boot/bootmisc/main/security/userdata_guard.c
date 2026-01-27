#include <stdio.h>
#include <unistd.h>
#include <sys/mount.h>
#include <errno.h>
#include <string.h>

#define USERDATA_MOUNT "/userdata"
#define AUTH_SOCKET   "/run/user_authority.sock"

static int is_user_authorized(void) {
    return access(AUTH_SOCKET, F_OK) == 0;
}

static void deny(const char *reason) {
    fprintf(stderr, "[guard] ACCESS DENIED: %s\n", reason);
}

int main(void) {
    printf("[guard] Userdata guard active\n");

    if (!is_user_authorized()) {
        deny("No user authority present");
        return 1;
    }

    if (mount(NULL,
              USERDATA_MOUNT,
              NULL,
              MS_REMOUNT,
              NULL) != 0) {
        deny(strerror(errno));
        return 1;
    }

    printf("[guard] Userdata remounted writable for user\n");

    while (1) {
        sleep(60);
        if (!is_user_authorized()) {
            mount(NULL,
                  USERDATA_MOUNT,
                  NULL,
                  MS_REMOUNT | MS_RDONLY,
                  NULL);
            printf("[guard] Authority lost, locking userdata\n");
            break;
        }
    }

    return 0;
}