#include <stdint.h>

uint32_t checksum32(const void *data, uint32_t size) {
    const uint8_t *p = data;
    uint32_t sum = 0;
    for (uint32_t i = 0; i < size; i++)
        sum += p[i];
    return sum;
}

int checksum_verify(const void *data, uint32_t size, uint32_t expect) {
    return checksum32(data, size) == expect;
}