#include <log.h>

static int cur_lvl = LOG_INFO;

void log_set_level(int lvl) {
    cur_lvl = lvl;
}

int log_allowed(int lvl) {
    return lvl >= cur_lvl;
}

void log_print(int lvl, const char *msg) {
    if (log_allowed(lvl))
        log_ring_write(msg);
}