static int cycles = 0;

void battery_cycle(void) {
    cycles++;
}

int battery_cycles(void) {
    return cycles;
}