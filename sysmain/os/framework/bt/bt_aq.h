#ifndef PALISADE_BT_AQ_H
#define PALISADE_BT_AQ_H

#include <stdint.h>

typedef enum {
    BT_AQ_PROFILE_LOW_LATENCY,
    BT_AQ_PROFILE_HIGH_QUALITY,
    BT_AQ_PROFILE_POWER_SAVE
} bt_aq_profile_t;

void bt_aq_set_profile(bt_aq_profile_t profile);
bt_aq_profile_t bt_aq_get_profile(void);

#endif