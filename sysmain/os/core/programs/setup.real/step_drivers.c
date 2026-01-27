#include <stdio.h>
#include <stdlib.h>

void step_drivers_execute(void)
{
    printf("Step 3. Install Drivers\n");
    printf("Compiling camera driver...\n");

    system("/palisade/os/setup/scripts/build_camera_driver.sh");

    printf("Camera driver ready.\n");
}