#include <stdint.h>
#include "../include/gui_common.h"

static struct gui_framebuffer fb;

void gui_arm_init(void) {
    fb.addr   = (volatile uint32_t *)0x50000000;
    fb.width  = 720;
    fb.height = 1280;

    gui_clear(&fb, GUI_COLOR_BLACK);
}

void gui_arm_draw(void) {
    gui_rect(&fb, 100, 100, 400, 200, GUI_COLOR_ORANGE);
}