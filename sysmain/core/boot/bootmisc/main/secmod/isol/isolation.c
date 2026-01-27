static int isolation_on = 0;

void isolation_enable(void) {
    isolation_on = 1;
}

int isolation_active(void) {
    return isolation_on;
}