#ifndef PALISADE_FRAMEBUFFER_H
#define PALISADE_FRAMEBUFFER_H

#include <stdint.h>

/*
 * Initializes /dev/fb0 mapping
 * Returns 0 on success, -1 on failure
 */
int fb_init(void);

/*
 * Clears the framebuffer to black
 */
void fb_clear(void);

/*
 * Draws a solid rectangle directly into the framebuffer
 *
 * x, y : top-left position
 * w, h : width and height
 * color: 0xAARRGGBB or 0x00RRGGBB depending on FB format
 */
void fb_draw_rect(int x, int y, int w, int h, uint32_t color);

/*
 * Present frame (noop for direct-mapped fb)
 */
void fb_render(void);

/*
 * Unmap framebuffer and close device
 */
void fb_shutdown(void);

#endif /* PALISADE_FRAMEBUFFER_H */