#include "ModeSwitcher.h"

ModeSwitcher::ModeSwitcher()
    : mode(KeyboardMode::QWERTY) {}

void ModeSwitcher::setMode(KeyboardMode m) {
    mode = m;
}

KeyboardMode ModeSwitcher::currentMode() const {
    return mode;
}

bool ModeSwitcher::isInputMode() const {
    return mode != KeyboardMode::SETTINGS;
}