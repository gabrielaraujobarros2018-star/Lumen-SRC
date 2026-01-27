#ifndef PALISADE_WIFI_AQUARIUM_H
#define PALISADE_WIFI_AQUARIUM_H

#include <stdint.h>

typedef enum {
    WIFI_STATE_DOWN = 0,
    WIFI_STATE_SCANNING,
    WIFI_STATE_ASSOCIATED,
    WIFI_STATE_ERROR
} wifi_state_t;

wifi_state_t wifi_get_state(void);
int wifi_request_scan(void);
int wifi_force_down(void);

#endif