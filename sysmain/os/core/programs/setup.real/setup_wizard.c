#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setup_wizard.h"

static setup_step_t current_step = STEP_WELCOME;

void wizard_render(void)
{
    switch (current_step) {
        case STEP_WELCOME:
            printf("Welcome!\nSetup Your Device in 3 Steps\n");
            break;

        case STEP_WIFI:
            system("/palisade/os/setup/scripts/wifi_scan.sh");
            break;

        case STEP_FRAMEWORK:
            system("/palisade/os/setup/scripts/install_framework.sh");
            break;

        case STEP_DRIVERS:
            system("/palisade/os/setup/scripts/build_camera_driver.sh");
            break;

        case STEP_DONE:
            printf("Setup Complete. System Ready.\n");
            break;
    }
}

void wizard_next(void)
{
    if (current_step < STEP_DONE)
        current_step++;
    wizard_render();
}

void wizard_start(void)
{
    current_step = STEP_WELCOME;
    wizard_render();
}