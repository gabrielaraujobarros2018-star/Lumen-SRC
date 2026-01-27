#include <stdint.h>

static volatile char *logbuf = (char *)0x110000;
static uint32_t logoff = 0;

void early_log(const char *msg) {
    if (!msg) return;

    while (*msg && logoff < 4096) {
        logbuf[logoff++] = *msg++;
    }

    if (logoff < 4096) {
        logbuf[logoff++] = '\n';
    }
}

uint32_t early_log_size(void) {
    return logoff;
}