#include <stdint.h>

struct surface_handle {
    uint32_t id;
    uint32_t width;
    uint32_t height;
};

static uint32_t next_surface_id = 1;

struct surface_handle surface_create(uint32_t w, uint32_t h) {
    struct surface_handle s;
    s.id = next_surface_id++;
    s.width = w;
    s.height = h;
    return s;
}