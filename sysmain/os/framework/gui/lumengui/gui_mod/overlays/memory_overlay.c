#include <overlay.h>
#include <memory.h>

void memory_overlay_render(void) {
    unsigned long total, free;
    page_stats(&total, &free);

    int percent = (free * 100) / total;
    draw_bar(10, 30, 120, 8, percent);

    char buf[32];
    snprintf(buf, sizeof(buf), "MEM %d%%", percent);
    draw_text(buf, 10, 45);
}