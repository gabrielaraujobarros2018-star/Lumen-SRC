#pragma once
#include <stdint.h>

class Framebuffer {
public:
    Framebuffer();
    void clear(uint32_t color);
    void draw_rect(int x, int y, int w, int h, uint32_t color);
    void draw_text(int x, int y, const char* text);
    void present();

private:
    uint32_t* fb;
    int width;
    int height;
    int pitch;
};