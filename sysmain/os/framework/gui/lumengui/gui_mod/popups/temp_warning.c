#include <popup.h>
#include <gui_module.h>

static struct popup tempwarn;

void temp_warning_init(void) {
    tempwarn.w = 360;
    tempwarn.h = 140;
    tempwarn.x = 50;
    tempwarn.y = 200;
}

void temp_warning_update(void) {
    if (thermal_celsius() > 70) {
        popup_show(&tempwarn);
        draw_text("Device Too Hot", tempwarn.x + 20, tempwarn.y + 40);
    }
}