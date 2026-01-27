static int runtime_allowed = 0;

void runtime_grant(void) {
    runtime_allowed = 1;
}

int runtime_check(void) {
    return runtime_allowed;
}