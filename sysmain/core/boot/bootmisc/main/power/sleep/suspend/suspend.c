static int suspended = 0;

void system_suspend(void) {
    suspended = 1;
}

int system_is_suspended(void) {
    return suspended;
}