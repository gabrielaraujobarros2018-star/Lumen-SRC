#include <stdint.h>

static int saved_profiles = 0;

void wifi_add_profile(void) {
    saved_profiles++;
}

int wifi_profile_count(void) {
    return saved_profiles;
}