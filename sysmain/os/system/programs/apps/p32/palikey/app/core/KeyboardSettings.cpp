#include "KeyboardSettings.h"

KeyboardSettings::KeyboardSettings()
    : spacingPx(4), keyboardScale(1.0f), useDarkTheme(true) {}

void KeyboardSettings::setKeySpacing(int px) {
    if (px > 0 && px < 50) {
        spacingPx = px;
    }
}

void KeyboardSettings::setScale(float scale) {
    if (scale >= 0.5f && scale <= 2.0f) {
        keyboardScale = scale;
    }
}

void KeyboardSettings::setDarkTheme(bool enabled) {
    useDarkTheme = enabled;
}

int KeyboardSettings::keySpacing() const {
    return spacingPx;
}

float KeyboardSettings::scale() const {
    return keyboardScale;
}

bool KeyboardSettings::darkTheme() const {
    return useDarkTheme;
}