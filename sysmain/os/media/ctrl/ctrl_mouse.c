#include <stdint.h>

static int mouse_x = 0;
static int mouse_y = 0;

void mouse_move(int dx, int dy) {
    mouse_x += dx;
    mouse_y += dy;
}

int mouse_get_x(void) {
    return mouse_x;
}

int mouse_get_y(void) {
    return mouse_y;
}