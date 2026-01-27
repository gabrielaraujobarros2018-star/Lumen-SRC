#include "framebuffer.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <stdint.h>
#include <errno.h>

/*
 * Global framebuffer state
 */
static int fb_fd = -1;
static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;
static uint8_t *fb_mem = NULL;
static size_t fb_size = 0;

/*
 * Initialize framebuffer device (/dev/fb0)
 */
int fb_init(void)
{
    fb_fd = open("/dev/fb0", O_RDWR);
    if (fb_fd < 0) {
        perror("fb_init: open");
        return -1;
    }

    if (ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("fb_init: FBIOGET_FSCREENINFO");
        close(fb_fd);
        fb_fd = -1;
        return -1;
    }

    if (ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("fb_init: FBIOGET_VSCREENINFO");
        close(fb_fd);
        fb_fd = -1;
        return -1;
    }

    fb_size = finfo.smem_len;

    fb_mem = mmap(
        NULL,
        fb_size,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        fb_fd,
        0
    );

    if (fb_mem == MAP_FAILED) {
        perror("fb_init: mmap");
        close(fb_fd);
        fb_fd = -1;
        fb_mem = NULL;
        return -1;
    }

    return 0;
}

/*
 * Clear framebuffer to black
 */
void fb_clear(void)
{
    if (!fb_mem)
        return;

    memset(fb_mem, 0x00, fb_size);
}

/*
 * Draw a single pixel (32bpp expected)
 */
static inline void fb_put_pixel(int x, int y, uint32_t color)
{
    if (!fb_mem)
        return;

    if (x < 0 || y < 0 ||
        x >= (int)vinfo.xres ||
        y >= (int)vinfo.yres)
        return;

    long location =
        (x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8) +
        (y + vinfo.yoffset) * finfo.line_length;

    *((uint32_t *)(fb_mem + location)) = color;
}

/*
 * Draw filled rectangle
 */
void fb_draw_rect(int x, int y, int w, int h, uint32_t color)
{
    if (!fb_mem)
        return;

    for (int py = y; py < y + h; py++) {
        for (int px = x; px < x + w; px++) {
            fb_put_pixel(px, py, color);
        }
    }
}

/*
 * Present frame
 * (noop for direct framebuffer access)
 */
void fb_render(void)
{
    /* Direct-mapped framebuffer; nothing to flush */
}

/*
 * Shutdown framebuffer
 */
void fb_shutdown(void)
{
    if (fb_mem && fb_mem != MAP_FAILED) {
        munmap(fb_mem, fb_size);
        fb_mem = NULL;
    }

    if (fb_fd >= 0) {
        close(fb_fd);
        fb_fd = -1;
    }
}