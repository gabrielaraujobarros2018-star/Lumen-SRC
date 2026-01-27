#include "gui.h"
#include "framebuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Wi-Fi setup step
 * Scans for available networks and presents them visually.
 */
void gui_wifi_step(void (*next)())
{
    int ret;

    /*
     * Initialize framebuffer
     */
    if (fb_init() != 0) {
        return;
    }

    /*
     * Clear screen
     */
    fb_clear();

    /*
     * Background
     */
    fb_draw_rect(
        0,
        0,
        800,
        480,
        0x00121212
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
     * Wi-Fi list panel
     */
    fb_draw_rect(
        40,
        80,
        720,
        280,
        0x00262626
    );

    /*
     * Simulated network entries
     * (visual representation only)
     */
    for (int i = 0; i < 3; i++) {
        fb_draw_rect(
            70,
            110 + (i * 60),
            660,
            40,
            0x00303030
        );
    }

    /*
     * Connect / Continue button
     */
    fb_draw_rect(
        560,
        380,
        200,
        60,
        0x003060FF
    );

    /*
     * Render UI
     */
    fb_render();

    /*
     * Perform real Wi-Fi scan (hosted environment)
     */
    ret = system(
        "iw dev 2>/dev/null | grep Interface >/dev/null || exit 0; "
        "iw dev wlan0 scan >/palisade/os/wifi_scan.txt 2>/dev/null"
    );

    (void)ret; /* scan failure is non-fatal */

    /*
     * Simulate user interaction delay
     */
    sleep(1);

    /*
     * Advance wizard
     */
    if (next != NULL) {
        next();
    }

    /*
     * Shutdown framebuffer
     */
    fb_shutdown();
}