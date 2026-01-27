#include <gui_module.h>

static int last_temp = 0;

void thermal_monitor_update(void) {
    int temp = thermal_celsius();
    if (temp != last_temp) {
        gui_event_push(GUI_EVENT_THERMAL, temp);
        last_temp = temp;
    }
}