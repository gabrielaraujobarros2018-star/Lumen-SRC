static int display_online = 0;

void display_enable(void) {
    display_online = 1;
}

int display_is_online(void) {
    return display_online;
}