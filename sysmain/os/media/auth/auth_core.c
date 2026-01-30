#include <stdint.h>

static int authenticated = 0;

void auth_login(void) {
    authenticated = 1;
}

void auth_logout(void) {
    authenticated = 0;
}

int auth_is_authenticated(void) {
    return authenticated;
}

void auth_reset(void) {
    authenticated = 0;
}

void auth_init(void) {
    auth_reset();
}