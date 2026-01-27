static int input_ready = 0;

void input_init(void) {
    input_ready = 1;
}

int input_is_ready(void) {
    return input_ready;
}