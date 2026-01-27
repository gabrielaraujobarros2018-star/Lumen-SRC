#include "bt_aq.h"
#include "../frameworks/framework.h"

static bt_aq_profile_t current_profile = BT_AQ_PROFILE_POWER_SAVE;

static int bt_aq_init(void) {
    current_profile = BT_AQ_PROFILE_POWER_SAVE;
    return 0;
}

static void bt_aq_shutdown(void) {
    /* No dynamic resources yet */
}

static void bt_aq_panic(void) {
    /* Force safest state */
    current_profile = BT_AQ_PROFILE_POWER_SAVE;
}

void bt_aq_set_profile(bt_aq_profile_t profile) {
    current_profile = profile;
}

bt_aq_profile_t bt_aq_get_profile(void) {
    return current_profile;
}

static framework_t bt_aq_framework = {
    .name = "Bluetooth Audio Quality",
    .version = 0x00010000,
    .state = FRAMEWORK_STATE_UNINITIALIZED,
    .init = bt_aq_init,
    .shutdown = bt_aq_shutdown,
    .panic = bt_aq_panic
};

__attribute__((constructor))
static void register_bt_aq(void) {
    framework_register(&bt_aq_framework);
}