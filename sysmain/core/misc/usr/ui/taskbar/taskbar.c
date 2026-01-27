#include <stdint.h>

static int visible = 1;

void taskbar_toggle(void) {
    visible = !visible;
}

int taskbar_visible(void) {
    return visible;
}

void taskbar_show(void) {
    visible = 1;
}