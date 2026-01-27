#include <stdint.h>

/* Forward declarations */
void gui_arm_init(void);
void gui_arm_draw(void);
void trigger_arm_poll(void);

/*
 * Single authoritative entry point
 * No libc
 * No return
 */
void main(void) {
    gui_arm_init();

    for (;;) {
        trigger_arm_poll();
        gui_arm_draw();
    }
}