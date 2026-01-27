#include <stddef.h>

void *memcpy(void *d, const void *s, size_t n) {
    char *dd = d;
    const char *ss = s;
    while (n--) *dd++ = *ss++;
    return d;
}