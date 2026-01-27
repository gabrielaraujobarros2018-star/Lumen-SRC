#include <stdio.h>
#include <string.h>

static char active_user[32];
static int session_active = 0;

int session_login(const char *user) {
    if (session_active) return -1;
    strncpy(active_user, user, sizeof(active_user) - 1);
    session_active = 1;
    printf("[session] user %s logged in\n", active_user);
    return 0;
}

int session_logout(void) {
    if (!session_active) return -1;
    printf("[session] user %s logged out\n", active_user);
    active_user[0] = 0;
    session_active = 0;
    return 0;
}

const char *session_current(void) {
    return session_active ? active_user : NULL;
}