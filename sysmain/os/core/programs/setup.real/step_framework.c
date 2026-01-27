#include <stdio.h>
#include <stdlib.h>

void step_framework_execute(void)
{
    printf("Step 2. Install Assets\n");
    printf("Installing framework.resX...\n");

    system("/palisade/os/setup/scripts/install_framework.sh");

    printf("Framework installation completed.\n");
}