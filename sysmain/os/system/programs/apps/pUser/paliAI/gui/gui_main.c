#include "pali_gui.h"

static gui_ctx_t g_gui;

void gui_init(gui_ctx_t *ctx)
{
    g_gui = *ctx;
}

void gui_start(void)
{
    gui_draw_text(16, 32, "PalisadeOS System Assistant");
    gui_draw_text(16, 64, "Status: Online");
    gui_present();
}