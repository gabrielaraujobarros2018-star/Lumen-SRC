#include <stdint.h>

long sys_write(long fd, const char *buf, long len) {
    (void)fd;
    if (!buf || len <= 0) return -1;

    volatile char *out = (char *)0x120000;
    for (long i = 0; i < len; i++) {
        out[i] = buf[i];
    }

    return len;
}

long sys_exit(long code) {
    (void)code;
    for (;;) {}
}