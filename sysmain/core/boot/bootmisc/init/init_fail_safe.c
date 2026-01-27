#include <init.h>

#define FAILSAFE_TIMEOUT_MS 5000

void init_fail_safe(void) {
    unsigned long start = timer_now();

    while (timer_now() - start < FAILSAFE_TIMEOUT_MS) {
        if (init_recoverable())
            return;
    }

    spawn_shell("/bin/rescue-sh");
    while (1) cpu_idle();
}