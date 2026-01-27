#include <safety_ui.h>

void thermal_ui_throttle(void) {
    if (thermal_celsius() > 75) {
        disable_blur_layers();
        disable_shadows();
        gui_set_low_power(1);
    }
}