#include "gui.h"
#include "framebuffer.h"

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * Assets / framework installation step
 * Downloads and extracts the Palisade framework
 * from the official repository.
 */
void gui_assets_step(void (*next)())
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
        0x00151515
    );

    /*
     * Header bar
     */
    fb_draw_rect(
        0,
        0,
        800,
        60,
        0x00202020
    );

    /*
     * Main content panel
     */
    fb_draw_rect(
        40,
        90,
        720,
        260,
        0x00252525
    );

    /*
     * Progress indicator blocks
     */
    for (int i = 0; i < 6; i++) {
        fb_draw_rect(
            70 + (i * 110),
            220,
            90,
            18,
            0x0040A0FF
        );
    }

    /*
     * Continue button (visual)
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
     * Ensure destination directory exists
     */
    mkdir("/palisade/os/framework", 0755);

    /*
     * Download framework repository
     */
    ret = system(
        "cd /palisade/os && "
        "rm -rf framework_tmp && "
        "git clone https://github.com/gabrielaraujobarros2018-star/framework_resX_Palisade framework_tmp"
    );

    if (ret != 0) {
        fb_shutdown();
        return;
    }

    /*
     * Move extracted framework into final location
     */
    ret = system(
        "cd /palisade/os && "
        "rm -rf framework && "
        "mv framework_tmp framework"
    );

    if (ret != 0) {
        fb_shutdown();
        return;
    }

    /*
     * Small delay to visually complete the step
     */
    sleep(1);

    /*
     * Advance wizard
     */
    if (next != 0) {
        next();
    }

    /*
     * Shutdown framebuffer
     */
    fb_shutdown();
}