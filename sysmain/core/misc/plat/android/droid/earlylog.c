#include "earlylog.h"

#define UART_BASE 0x09000000UL
static volatile unsigned char *uart = (unsigned char *)UART_BASE;

void earlylog(const char *msg) {
    if (!msg) return;
    while (*msg) {
        *uart = *msg++;
    }
    *uart = '\n';
}