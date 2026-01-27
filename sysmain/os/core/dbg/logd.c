#include <log.h>

void logd_run(void) {
    char buf[256];

    while (1) {
        if (log_fetch(buf, sizeof(buf))) {
            console_write(buf);
        }
        task_sleep(1);
    }
}