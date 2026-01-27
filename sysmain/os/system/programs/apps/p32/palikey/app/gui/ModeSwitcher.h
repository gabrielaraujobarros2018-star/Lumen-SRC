#ifndef PALIKEY_MODE_SWITCHER_H
#define PALIKEY_MODE_SWITCHER_H

#include "../core/KeyboardMode.h"

class ModeSwitcher {
public:
    ModeSwitcher();

    void setMode(KeyboardMode m);
    KeyboardMode currentMode() const;
    bool isInputMode() const;

private:
    KeyboardMode mode;
};

#endif