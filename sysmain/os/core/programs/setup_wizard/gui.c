#include "gui.h"
#include "framebuffer.h"

#include <unistd.h>

/*
 * Forward declarations of step functions
 * implemented in their respective compilation units
 */
void gui_assets_step(void (*next)());
void gui_drivers_step(void (*next)());

/*
 * Wizard flow control functions
 */
static void wizard_assets_next(void);
static void wizard_drivers_next(void);
static void wizard_finish(void);

/*
 * Welcome screen
 */
void gui_welcome(void (*next)())
{
    if (fb_init() != 0) {
        return;
    }

    fb_clear();

    /*
     * Background
     */
    fb_draw_rect(
        0,
        0,
        800,
        480,
        0x00101010
    );

    /*
     * Header
     */
    fb_draw_rect(
        0,
        0,
        800,
        60,
        0x00202020
    );

    /*
     * Welcome panel
     */
    fb_draw_rect(
        100,
        140,
        600,
        180,
        0x00252525
    );

    /*
     * Continue button
     */
    fb_draw_rect(
        560,
        380,
        200,
        60,
        0x003060FF
    );

    fb_render();

    /*
     * Simulate user reading screen
     */
    sleep(1);

    fb_shutdown();

    if (next) {
        next();
    }
}

/*
 * Transition: Welcome → Assets
 */
static void __attribute__((unused)) wizard_assets_next(void)
{
    gui_assets_step(wizard_drivers_next);
}

/*
 * Transition: Assets → Drivers
 */
static void wizard_drivers_next(void)
{
    gui_drivers_step(wizard_finish);
}

/*
 * Final screen
 */
static void wizard_finish(void)
{
    if (fb_init() != 0) {
        return;
    }

    fb_clear();

    fb_draw_rect(
        0,
        0,
        800,
        480,
        0x00151515
    );

    fb_draw_rect(
        120,
        160,
        560,
        160,
        0x00282828
    );

    fb_render();

    sleep(1);

    fb_shutdown();
}
