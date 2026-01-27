#include <sch.h>

void sch_idle_run(void) {
    if (device_class() == DEV_MOBILE) {
        cpu_enter_low_power();
        timer_sleep(10);
    } else {
        cpu_halt();
    }
}

void sch_idle_tick(void) {
    if (no_runnable_tasks())
        sch_idle_run();
}