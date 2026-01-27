static int runtime_ready = 0;

void runtime_init(void) {
    runtime_ready = 1;
}

int runtime_is_ready(void) {
    return runtime_ready;
}