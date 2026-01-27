#include <stdio.h>
#include <stdlib.h>

void step_wifi_execute(void)
{
    printf("Step 1. Set Default Wi-Fi\n");
    printf("Searching for available networks...\n");

    system("/palisade/os/setup/scripts/wifi_scan.sh");

    printf("Use CONNECT button to attach.\n");
}