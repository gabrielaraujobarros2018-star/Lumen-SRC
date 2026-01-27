#include "pali_gui.h"

static uint32_t *fb_base;

void gui_draw_text(int x, int y, const char *s)
{
    int i = 0;
    while (s[i]) {
        int px = x + (i * 8);
        int py = y;
        fb_base[(py * GUI_W) + px] = 0xFFFFFFFF;
        i++;
    }
}

void gui_present(void)
{
    /* framebuffer already live */
}