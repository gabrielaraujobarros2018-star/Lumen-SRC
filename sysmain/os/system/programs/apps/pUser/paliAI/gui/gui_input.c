#include <stdint.h>

static volatile uint32_t *touch_reg =
    (uint32_t *)0xFFFF000000004000;

int gui_poll_input(void)
{
    uint32_t v = *touch_reg;
    if (v)
        return 1;

    return 0;
}