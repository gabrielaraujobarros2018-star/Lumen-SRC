#pragma once
#include <string>
#include <vector>

namespace palisade::features::screenshots {

class ScreenshotManager {
public:
    ScreenshotManager();
    void requestCapture();
    void setEnabled(bool state);
    bool isEnabled() const;

private:
    bool enabled;
    void notifyUI();
    std::string generateFilename() const;
};

}