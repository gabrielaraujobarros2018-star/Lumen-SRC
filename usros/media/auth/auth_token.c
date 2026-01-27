#include <stdint.h>

static uint64_t session_token = 0;

void auth_token_set(uint64_t token) {
    session_token = token;
}

uint64_t auth_token_get(void) {
    return session_token;
}

void auth_token_clear(void) {
    session_token = 0;
}

int auth_token_valid(void) {
    return session_token != 0;
}

void auth_token_init(void) {
    session_token = 0;
}