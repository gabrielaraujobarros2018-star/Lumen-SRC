#include <stdio.h>
#include <stdarg.h>

void hal_log(const char *tag, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printf("[HAL][%s] ", tag);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}