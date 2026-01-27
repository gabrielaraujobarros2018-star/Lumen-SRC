#pragma once
#include <stdint.h>
#include <stddef.h>

namespace system {

struct BootInfo {
    uint32_t fb_width;
    uint32_t fb_height;
    uint32_t fb_pitch;
    uint32_t fb_bpp;
    void* framebuffer;
};

void halt();
void reboot();
void log(const char* msg);
BootInfo* bootinfo();

}