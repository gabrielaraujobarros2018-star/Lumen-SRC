#include <stdint.h>

static volatile char *bootlog_buf = (char *)0x100000;
static uint32_t bootlog_off = 0;

void boot_log(const char *msg) {
    if (!msg) return;

    while (*msg && bootlog_off < 4096) {
        bootlog_buf[bootlog_off++] = *msg++;
    }

    if (bootlog_off < 4096) {
        bootlog_buf[bootlog_off++] = '\n';
    }
}

void boot_log_hex(uint64_t v) {
    static const char hex[] = "0123456789ABCDEF";
    for (int i = 60; i >= 0; i -= 4) {
        char c = hex[(v >> i) & 0xF];
        bootlog_buf[bootlog_off++] = c;
    }
    bootlog_buf[bootlog_off++] = '\n';
}