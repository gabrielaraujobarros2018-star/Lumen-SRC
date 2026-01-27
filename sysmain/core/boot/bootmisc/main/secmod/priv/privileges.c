static int privileged = 0;

void privilege_escalate(void) {
    privileged = 1;
}

int is_privileged(void) {
    return privileged;
}