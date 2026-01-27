static int fastcharge_enabled = 0;

void fastcharge_enable(void) {
    fastcharge_enabled = 1;
}

int fastcharge_active(void) {
    return fastcharge_enabled;
}