#include <power_ui.h>
#include <gui_module.h>

static int active = 0;

void power_saver_enable(void) {
    active = 1;
    gui_set_low_power(1);
    shader_load("light_ui.shader");
}

void power_saver_disable(void) {
    active = 0;
    gui_set_low_power(0);
}

int power_saver_active(void) {
    return active;
}