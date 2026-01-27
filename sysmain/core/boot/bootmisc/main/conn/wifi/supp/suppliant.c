#include <stdint.h>

static int authenticated = 0;

void wifi_authenticate(void) {
    authenticated = 1;
}

int wifi_is_authenticated(void) {
    return authenticated;
}