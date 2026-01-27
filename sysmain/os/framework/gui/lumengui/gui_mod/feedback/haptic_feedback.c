#include <feedback.h>

void haptic_click(void) {
    hw_haptic_pulse(10);
}

void haptic_warning(void) {
    hw_haptic_pulse(30);
    hw_haptic_pulse(30);
}

void haptic_confirm(void) {
    hw_haptic_pulse(15);
}