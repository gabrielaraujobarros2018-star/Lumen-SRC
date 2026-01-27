#ifndef PALI_GUI_H
#define PALI_GUI_H

#include <stdint.h>

#define GUI_W 720
#define GUI_H 1280

typedef struct {
    uint32_t *fb;
    uint32_t pitch;
} gui_ctx_t;

void gui_init(gui_ctx_t *ctx);
void gui_draw_text(int x, int y, const char *s);
void gui_present(void);

#endif