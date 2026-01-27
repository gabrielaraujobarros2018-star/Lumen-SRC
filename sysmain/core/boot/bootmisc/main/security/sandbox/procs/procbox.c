static int proc_isolated = 1;

void procbox_open(void) {
    proc_isolated = 0;
}

int procbox_active(void) {
    return proc_isolated;
}