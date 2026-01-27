#pragma once
#include <stdint.h>

/*
 * gui_common.h
 * Shared low-level GUI primitives for boot/recovery programs
 * No libc usage
 * No heap usage
 */

#define GUI_COLOR_BLACK   0x00000000
#define GUI_COLOR_RED     0x00FF0000
#define GUI_COLOR_GREEN   0x0000FF00
#define GUI_COLOR_BLUE    0x000000FF
#define GUI_COLOR_ORANGE  0x00FFAA00
#define GUI_COLOR_GRAY    0x00333333

struct gui_framebuffer {
    volatile uint32_t *addr;
    uint32_t width;
    uint32_t height;
};

static inline void gui_clear(struct gui_framebuffer *fb, uint32_t color) {
    if (!fb || !fb->addr)
        return;

    uint32_t total = fb->width * fb->height;
    for (uint32_t i = 0; i < total; i++) {
        fb->addr[i] = color;
    }
}

static inline void gui_rect(
    struct gui_framebuffer *fb,
    uint32_t x,
    uint32_t y,
    uint32_t w,
    uint32_t h,
    uint32_t color
) {
    if (!fb || !fb->addr)
        return;

    for (uint32_t j = y; j < y + h; j++) {
        for (uint32_t i = x; i < x + w; i++) {
            fb->addr[j * fb->width + i] = color;
        }
    }
}

/*
 * This header intentionally:
 * - Avoids fonts
 * - Avoids text rendering
 * - Avoids dynamic scaling
 */