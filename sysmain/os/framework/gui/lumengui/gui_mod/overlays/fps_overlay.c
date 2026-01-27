#include <overlay.h>

static int frame_count = 0;
static float elapsed = 0.0f;
static int fps = 0;

void fps_overlay_update(void) {
    frame_count++;
    elapsed += frame_delta();

    if (elapsed >= 1.0f) {
        fps = frame_count;
        frame_count = 0;
        elapsed = 0.0f;
    }
}

void fps_overlay_render(void) {
    char buf[32];
    snprintf(buf, sizeof(buf), "FPS: %d", fps);
    draw_text(buf, 10, 10);
}