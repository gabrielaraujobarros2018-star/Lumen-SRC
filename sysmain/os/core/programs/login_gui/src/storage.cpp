#include "storage.hpp"

static UserProfile stored;
static bool exists = false;

bool save_user(const UserProfile& profile) {
    stored = profile;
    exists = true;
    return true;
}

bool user_exists() {
    return exists;
}