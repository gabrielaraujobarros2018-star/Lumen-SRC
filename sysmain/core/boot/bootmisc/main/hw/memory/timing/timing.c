static uint64_t uptime_ticks = 0;

void timer_tick(void) {
    uptime_ticks++;
}