#pragma once
#include <stdint.h>

void early_log(const char *);
long sys_write(long, const char *, long);
uint32_t scheduler_yield(void);

struct resolution {
    uint32_t width;
    uint32_t height;
};

struct ui_context {
    struct resolution res;
    uint32_t scale;
};