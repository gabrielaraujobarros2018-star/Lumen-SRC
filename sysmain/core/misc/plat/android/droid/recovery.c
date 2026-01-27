#include "recovery.h"
#include "../earlylog.h"

static uint32_t boot_failures;

void recovery_record_failure(void) {
    boot_failures++;
    earlylog("recovery: boot failure recorded");
}

int recovery_should_rollback(void) {
    if (boot_failures >= MAX_BOOT_FAILURES) {
        earlylog("recovery: rollback triggered");
        return 1;
    }
    return 0;
}