#include <gui_module.h>

static int last_level = 100;

void battery_monitor_update(void) {
    int level = battery_percent();
    if (level != last_level) {
        gui_event_push(GUI_EVENT_BATTERY, level);
        last_level = level;
    }
}