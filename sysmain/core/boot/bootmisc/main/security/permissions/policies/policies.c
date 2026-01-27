static int allow_all = 0;

void policy_allow_all(void) {
    allow_all = 1;
}

int policy_is_open(void) {
    return allow_all;
}