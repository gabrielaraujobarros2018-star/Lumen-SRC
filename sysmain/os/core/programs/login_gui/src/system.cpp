#include "system.hpp"

static system::BootInfo boot;

namespace system {

BootInfo* bootinfo() {
    return &boot;
}

void log(const char* msg) {
    volatile char* serial = (volatile char*)0x09000000;
    while (*msg) {
        *serial = *msg++;
    }
}

void halt() {
    log("System halt\n");
    for (;;) {
        asm volatile("wfi");
    }
}

void reboot() {
    log("System reboot\n");
    volatile uint32_t* reset = (volatile uint32_t*)0x100000;
    *reset = 0x1;
    halt();
}

}