#include <feedback.h>

void visual_flash(int strength) {
    set_ui_overlay_alpha(0.1f * strength);
}

void visual_warning_flash(void) {
    visual_flash(4);
}

void visual_confirm_flash(void) {
    visual_flash(2);
}