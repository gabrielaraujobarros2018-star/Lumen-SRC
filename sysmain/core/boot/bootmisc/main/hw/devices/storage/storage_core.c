static int storage_ready = 0;

void storage_init(void) {
    storage_ready = 1;
}

int storage_is_ready(void) {
    return storage_ready;
}