#include <stdint.h>
#include "../include/trigger_common.h"

/*
 * ARM Recovery Trigger Logic
 * - Volume Up / Down navigation
 * - Power key confirmation
 * - No delays
 * - Edge-based input
 */

static struct trigger_state vol_up;
static struct trigger_state vol_down;
static struct trigger_state power_key;

/* GUI hook */
void gui_recovery_arm_set_active(int index);

/* Selection state */
static int current_selection = 0;
static const int max_selection = 3;

/* Platform stubs (replace with real GPIO / input reads) */
static uint32_t platform_read_volume_up(void) {
    return 0;
}

static uint32_t platform_read_volume_down(void) {
    return 0;
}

static uint32_t platform_read_power(void) {
    return 0;
}

static void platform_execute_action(int selection) {
    switch (selection) {
        case 0:
            /* Reboot system */
            break;
        case 1:
            /* Factory reset */
            break;
        case 2:
            /* Apply update */
            break;
        default:
            break;
    }
}

void trigger_recovery_arm_poll(void) {
    uint32_t up    = platform_read_volume_up();
    uint32_t down  = platform_read_volume_down();
    uint32_t power = platform_read_power();

    if (trigger_fired(&vol_up, up)) {
        current_selection--;
        if (current_selection < 0)
            current_selection = max_selection - 1;
        gui_recovery_arm_set_active(current_selection);
    }

    if (trigger_fired(&vol_down, down)) {
        current_selection++;
        if (current_selection >= max_selection)
            current_selection = 0;
        gui_recovery_arm_set_active(current_selection);
    }

    if (trigger_fired(&power_key, power)) {
        platform_execute_action(current_selection);
    }
}

/*
 * Design guarantees:
 * - No accidental execution
 * - All actions are explicit
 * - No state persists across reboot
 *
 * Recovery must always be predictable.
 */