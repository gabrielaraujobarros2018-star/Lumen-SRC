#include <gui_module.h>

static struct gui_state state;

void gui_state_init(void) {
    state.anim_speed = 1.5f;
    state.low_power = 0;
    state.ui_brightness = 1.0f;
}

void gui_set_low_power(int on) {
    state.low_power = on;
    if (on)
        state.anim_speed = 1.0f;
    else
        state.anim_speed = 1.5f;
}

float gui_anim_speed(void) {
    return state.anim_speed;
}