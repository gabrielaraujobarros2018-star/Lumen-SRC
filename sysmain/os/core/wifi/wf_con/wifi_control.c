#include <stdlib.h>
#include <stdio.h>
#include "wifi_control.h"
#include "palisade_ap.h"

void palisade_wifi_init(void)
{
    system("ip link set wlan0 up");
    palisade_start_ap_2ghz();
}

void palisade_wifi_shutdown(void)
{
    palisade_stop_ap();
    system("ip link set wlan0 down");
}