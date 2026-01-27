#include <stdint.h>

extern void system_log(const char *);
extern int framework_init_all(void);
extern int driver_init_all(void);

int program_init_system_services(void) {
    system_log("INIT: Starting system services");

    if (framework_init_all() != 0) {
        system_log("INIT: Framework init failed");
        return -1;
    }

    if (driver_init_all() != 0) {
        system_log("INIT: Driver init failed");
        return -2;
    }

    system_log("INIT: System services ready");
    return 0;
}

/* ABI-mandated entry point */
int program_main(void) {
    return program_init_system_services();
}