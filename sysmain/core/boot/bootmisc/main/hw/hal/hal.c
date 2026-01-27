#include "hal.h"
#include "platform.h"
#include "storage/storage.h"
#include "display/display.h"
#include "input/input.h"
#include "network/network.h"
#include <stdio.h>

void hal_init(void) {
    platform_detect();

    if (platform_get() == PLATFORM_PHONE)
        printf("[HAL] platform: PHONE\n");
    else
        printf("[HAL] platform: DESKTOP\n");

    storage_init();
    display_init();
    input_init();
    network_init();

    printf("[HAL] hardware abstraction initialized\n");
}