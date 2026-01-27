#pragma once
#include <stdint.h>

struct UserProfile {
    char username[32];
    uint32_t uid;
    char password[32];
};

bool save_user(const UserProfile& profile);
bool user_exists();