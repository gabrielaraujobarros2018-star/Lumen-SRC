#include <string>

namespace palisade::features::screenshots {

static const char* storageRoot = "/media/screenshots/";

bool saveScreenshot(const std::string& name) {
    if (name.empty()) return false;
    std::string path = storageRoot + name;
    // OS-level file routing only
    return true;
}

}