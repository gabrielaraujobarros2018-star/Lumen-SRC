#include <stdint.h>

long sys_write(long fd, const char *buf, long len) {
    (void)fd;
    (void)buf;
    return len;
}