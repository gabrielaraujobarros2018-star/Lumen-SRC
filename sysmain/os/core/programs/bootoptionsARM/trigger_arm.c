#include <stdint.h>
#include "../include/trigger_common.h"

static struct trigger_state f11;
static struct trigger_state vol_up;

void trigger_arm_poll(void) {
    uint32_t f11_state    = 0; /* platform hook */
    uint32_t volume_state = 0; /* platform hook */

    if (trigger_fired(&f11, f11_state)) {
        /* Enter boot options */
    }

    if (trigger_fired(&vol_up, volume_state)) {
        /* Enter recovery */
    }
}