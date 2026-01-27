#include "gui.h"
#include "framebuffer.h"

#include <unistd.h>

/*
 * Forward declaration of wizard continuation
 */
static void wizard_start_assets(void);

/*
 * Entry point for setup wizard
 */
int main(void)
{
    /*
     * Start the setup wizard at the welcome screen.
     * The welcome screen will advance using callbacks.
     */
    gui_welcome(wizard_start_assets);

    /*
     * Prevent immediate process exit.
     * In a real environment this would be event-driven.
     */
    while (1) {
        sleep(1);
    }

    return 0;
}

/*
 * Transition from welcome screen to assets step
 */
static void wizard_start_assets(void)
{
    gui_assets_step(NULL);
}