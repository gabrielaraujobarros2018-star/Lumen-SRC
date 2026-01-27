#include <popup.h>
#include <gui_module.h>

static struct popup lowbat;

void low_battery_init(void) {
    lowbat.w = 320;
    lowbat.h = 120;
    lowbat.x = 40;
    lowbat.y = 40;
}

void low_battery_update(void) {
    if (battery_percent() < 15) {
        popup_show(&lowbat);
        draw_text("Low Battery", lowbat.x + 20, lowbat.y + 30);
    }
}