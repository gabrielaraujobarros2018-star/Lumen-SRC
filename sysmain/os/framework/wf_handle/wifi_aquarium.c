#include "wifi_aquarium.h"
#include "../frameworks/framework.h"

static wifi_state_t wifi_state = WIFI_STATE_DOWN;

static int wifi_init(void) {
    wifi_state = WIFI_STATE_DOWN;
    return 0;
}

static void wifi_shutdown(void) {
    wifi_state = WIFI_STATE_DOWN;
}

static void wifi_panic(void) {
    wifi_state = WIFI_STATE_ERROR;
}

wifi_state_t wifi_get_state(void) {
    return wifi_state;
}

int wifi_request_scan(void) {
    if (wifi_state != WIFI_STATE_DOWN)
        return -1;

    wifi_state = WIFI_STATE_SCANNING;
    return 0;
}

int wifi_force_down(void) {
    wifi_state = WIFI_STATE_DOWN;
    return 0;
}

static framework_t wifi_framework = {
    .name = "WiFi Handler Aquarium",
    .version = 0x00010000,
    .state = FRAMEWORK_STATE_UNINITIALIZED,
    .init = wifi_init,
    .shutdown = wifi_shutdown,
    .panic = wifi_panic
};

__attribute__((constructor))
static void register_wifi(void) {
    framework_register(&wifi_framework);
}