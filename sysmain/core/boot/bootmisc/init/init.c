#include "../userland/include/userland.h"

extern int shell_main(void);

void init_mounts(void) {
    early_log("init: mounts ready");
}

void init_devices(void) {
    early_log("init: devices ready");
}

void init_services(void) {
    early_log("init: services ready");
}

int init_main(void) {
    early_log("Palisade-init starting");

    init_mounts();
    init_devices();
    init_services();

    early_log("launching shell");
    shell_main();

    for (;;) {
        scheduler_yield();
    }
}