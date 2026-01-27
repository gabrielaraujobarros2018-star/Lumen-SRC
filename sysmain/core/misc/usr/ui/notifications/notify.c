#include <stdint.h>

static uint32_t notifications = 0;

void notify_push(const char *msg) {
    (void)msg;
    notifications++;
}

uint32_t notify_count(void) {
    return notifications;
}

void notify_clear(void) {
    notifications = 0;
}