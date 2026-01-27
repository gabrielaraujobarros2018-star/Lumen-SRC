#include "pali_util.h"
#include <stdint.h>

int pali_strcmp(const char *a, const char *b)
{
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return *(const unsigned char *)a -
           *(const unsigned char *)b;
}

void pali_log(const char *s)
{
    volatile uint32_t *fb =
        (uint32_t *)0xFFFF000000010000;

    int i = 0;
    while (s[i]) {
        fb[i] = 0xFFFFFFFF;
        i++;
    }
}