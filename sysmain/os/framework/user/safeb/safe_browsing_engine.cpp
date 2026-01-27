#include "safe_browsing_engine.hpp"

namespace palisade::features::safe {

static bool enabled = true;

void enableProtection(bool state) {
    enabled = state;
}

bool isUrlSafe(const std::string& url) {
    if (!enabled) return true;
    return url.find("phish") == std::string::npos;
}

}