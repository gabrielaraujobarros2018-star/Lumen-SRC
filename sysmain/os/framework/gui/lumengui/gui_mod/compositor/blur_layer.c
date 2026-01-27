#include <compositor.h>

void blur_layer_render(void) {
    shader_load("soft_shadow.shader");
    draw_fullscreen_quad();
    shader_disable();
}