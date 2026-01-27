#include <popup.h>
#include <power_ui.h>

static struct popup charge;

void charging_popup_update(void) {
    if (charger_connected()) {
        popup_show(&charge);
        draw_text("Charging", charge.x + 20, charge.y + 30);
    } else {
        popup_hide(&charge);
    }
}