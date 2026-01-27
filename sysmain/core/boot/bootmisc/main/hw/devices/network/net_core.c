static int net_up = 0;

void net_enable(void) {
    net_up = 1;
}

int net_is_up(void) {
    return net_up;
}