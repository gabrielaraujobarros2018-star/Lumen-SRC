#include <safety_ui.h>

static float idle_time = 0;

void screen_dim_update(void) {
    idle_time += frame_delta();
    if (idle_time > 60.0f)
        set_screen_brightness(0.6f);
}

void screen_activity_event(void) {
    idle_time = 0;
    set_screen_brightness(1.0f);
}