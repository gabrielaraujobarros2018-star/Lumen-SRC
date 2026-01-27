#pragma once
#include <stdint.h>

#define MAX_BOOT_FAILURES 3

void recovery_record_failure(void);
int  recovery_should_rollback(void);