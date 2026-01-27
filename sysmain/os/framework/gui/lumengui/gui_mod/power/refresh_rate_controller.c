#include <power_ui.h>

void refresh_rate_update(void) {
    if (power_saver_active())
        gpu_set_refresh_rate(60);
    else
        gpu_set_refresh_rate(90);
}