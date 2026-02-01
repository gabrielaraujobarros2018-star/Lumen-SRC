#include <stdint.h>

static uint32_t policy_mask = 0;

void auth_policy_allow(uint32_t p) {
    policy_mask |= p;
}

void auth_policy_deny(uint32_t p) {
    policy_mask &= ~p;
}

int auth_policy_check(uint32_t p) {
    return (policy_mask & p) != 0;
}

void auth_policy_reset(void) {
    policy_mask = 0;
}

void auth_policy_init(void) {
    auth_policy_reset();
}