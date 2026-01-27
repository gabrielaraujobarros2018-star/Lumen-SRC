#include <boot.h>

#define BOOTLOG_SIZE 8192

static char bootlog_buffer[BOOTLOG_SIZE];
static unsigned int bootlog_index = 0;

void bootlog_init(void) {
    bootlog_index = 0;
    for (unsigned int i = 0; i < BOOTLOG_SIZE; i++)
        bootlog_buffer[i] = 0;
}

void bootlog_write(const char *msg) {
    if (!msg) return;

    while (*msg && bootlog_index < BOOTLOG_SIZE - 1) {
        bootlog_buffer[bootlog_index++] = *msg++;
    }
    bootlog_buffer[bootlog_index] = '\0';
}

const char *bootlog_get(void) {
    return bootlog_buffer;
}

unsigned int bootlog_size(void) {
    return bootlog_index;
}