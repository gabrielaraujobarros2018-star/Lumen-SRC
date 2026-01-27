#include <safety_ui.h>

static int shift = 0;

void burn_in_shift_update(void) {
    shift = (shift + 1) % 4;
    set_ui_offset(shift, shift);
}