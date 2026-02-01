#include <stdio.h>
#include <time.h>

static time_t last_tick;

void watchdog_kick(void) {
    last_tick = time(NULL);
}

void watchdog_check(void) {
    if (time(NULL) - last_tick > 5)
        printf("Watchdog warning\n");
}

void watchdog_init(void) {
    watchdog_kick();
}