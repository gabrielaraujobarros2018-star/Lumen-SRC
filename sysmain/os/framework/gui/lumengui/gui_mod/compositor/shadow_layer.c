#include <compositor.h>

void shadow_layer_render(void) {
    shader_load("soft_shadow.shader");
    render_ui_geometry();
    shader_disable();
}