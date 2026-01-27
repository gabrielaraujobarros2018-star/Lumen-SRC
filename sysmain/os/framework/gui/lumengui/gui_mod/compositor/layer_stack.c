#include <compositor.h>

static struct layer layers[16];
static int count = 0;

void layer_push(struct layer *l) {
    if (count < 16)
        layers[count++] = *l;
}

void layer_render_all(void) {
    for (int i = 0; i < count; i++)
        layers[i].render();
}