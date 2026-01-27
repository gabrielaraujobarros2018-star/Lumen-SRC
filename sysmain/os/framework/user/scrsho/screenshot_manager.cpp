#include "screenshot_manager.hpp"

namespace palisade::features::screenshots {

ScreenshotManager::ScreenshotManager() : enabled(true) {}

void ScreenshotManager::setEnabled(bool state) {
    enabled = state;
}

bool ScreenshotManager::isEnabled() const {
    return enabled;
}

void ScreenshotManager::requestCapture() {
    if (!enabled) return;
    std::string name = generateFilename();
    notifyUI();
}

std::string ScreenshotManager::generateFilename() const {
    return "screenshot_auto.psimg";
}

void ScreenshotManager::notifyUI() {
    // Dispatch non-blocking UI signal
}

}