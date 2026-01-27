#include <stdint.h>
#include "../include/gui_common.h"

/*
 * ARM Recovery GUI
 * - Framebuffer only
 * - No text rendering
 * - Deterministic layout
 * - Touch / key neutral
 */

static struct gui_framebuffer fb;

/* Layout constants */
#define BG_COLOR        GUI_COLOR_BLACK
#define PANEL_COLOR     GUI_COLOR_GRAY
#define ACTIVE_COLOR    GUI_COLOR_ORANGE
#define BORDER_COLOR    GUI_COLOR_GREEN

#define PANEL_WIDTH     560
#define PANEL_HEIGHT    96
#define PANEL_SPACING   32

enum recovery_panel_id {
    PANEL_REBOOT = 0,
    PANEL_FACTORY_RESET,
    PANEL_UPDATE,
    PANEL_COUNT
};

struct recovery_panel {
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;
    int      active;
};

static struct recovery_panel panels[PANEL_COUNT];

static void draw_panel(struct recovery_panel *p) {
    if (!p)
        return;

    uint32_t color = p->active ? ACTIVE_COLOR : PANEL_COLOR;
    gui_rect(&fb, p->x, p->y, p->w, p->h, color);

    /* Border */
    gui_rect(&fb, p->x, p->y, p->w, 2, BORDER_COLOR);
    gui_rect(&fb, p->x, p->y + p->h - 2, p->w, 2, BORDER_COLOR);
    gui_rect(&fb, p->x, p->y, 2, p->h, BORDER_COLOR);
    gui_rect(&fb, p->x + p->w - 2, p->y, 2, p->h, BORDER_COLOR);
}

void gui_recovery_arm_init(void) {
    fb.addr   = (volatile uint32_t *)0x50000000;
    fb.width  = 720;
    fb.height = 1280;

    gui_clear(&fb, BG_COLOR);

    uint32_t start_y = 280;
    uint32_t x = (fb.width - PANEL_WIDTH) / 2;

    for (int i = 0; i < PANEL_COUNT; i++) {
        panels[i].x = x;
        panels[i].y = start_y + i * (PANEL_HEIGHT + PANEL_SPACING);
        panels[i].w = PANEL_WIDTH;
        panels[i].h = PANEL_HEIGHT;
        panels[i].active = (i == 0);
    }
}

void gui_recovery_arm_set_active(int index) {
    for (int i = 0; i < PANEL_COUNT; i++) {
        panels[i].active = (i == index);
    }
}

void gui_recovery_arm_draw(void) {
    gui_clear(&fb, BG_COLOR);

    for (int i = 0; i < PANEL_COUNT; i++) {
        draw_panel(&panels[i]);
    }

    /* Status bar */
    gui_rect(&fb, 0, 0, fb.width, 48, GUI_COLOR_GRAY);
}

/*
 * Intentional omissions:
 * - No fonts
 * - No animations
 * - No transparency
 *
 * Recovery must be boring and reliable.
 */