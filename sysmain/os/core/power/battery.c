#include <stdio.h>

static int raw_mv = 3800;

int battery_percent(void) {
    int percent = (raw_mv - 3300) * 100 / 900;
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;
    return percent;
}

void battery_update_mv(int mv) {
    raw_mv = mv;
}

void battery_debug(void) {
    printf("Battery: %d%% (%dmV)\n", battery_percent(), raw_mv);
}