#include <shader.h>

static struct shader active_shader;

int shader_load(const char *name) {
    active_shader.handle = gpu_load_shader(name);
    return active_shader.handle ? 0 : -1;
}

void shader_apply(void) {
    if (active_shader.handle)
        gpu_bind_shader(active_shader.handle);
}

void shader_disable(void) {
    gpu_unbind_shader();
}