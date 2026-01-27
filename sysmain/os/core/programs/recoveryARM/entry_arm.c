#include <stdint.h>

/* Forward declarations */
void gui_recovery_arm_init(void);
void gui_recovery_arm_draw(void);
void trigger_recovery_arm_poll(void);

/*
 * Recovery ARM entry point
 * Freestanding, no return
 */
void _start(void) {
    gui_recovery_arm_init();

    for (;;) {
        trigger_recovery_arm_poll();
        gui_recovery_arm_draw();
    }
}