#include "framebuffer.hpp"
#include "system.hpp"

Framebuffer::Framebuffer() {
    auto* bi = system::bootinfo();
    fb = (uint32_t*)bi->framebuffer;
    width = bi->fb_width;
    height = bi->fb_height;
    pitch = bi->fb_pitch / 4;
}

void Framebuffer::clear(uint32_t color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fb[y * pitch + x] = color;
        }
    }
}

void Framebuffer::draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int iy = 0; iy < h; iy++) {
        for (int ix = 0; ix < w; ix++) {
            fb[(y + iy) * pitch + (x + ix)] = color;
        }
    }
}

void Framebuffer::draw_text(int x, int y, const char* text) {
    while (*text) {
        draw_rect(x, y, 8, 12, 0xFFFFFFFF);
        x += 10;
        text++;
    }
}

void Framebuffer::present() {}