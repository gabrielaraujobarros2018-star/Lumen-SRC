#ifndef PALIKEY_KEYBOARD_MODE_H
#define PALIKEY_KEYBOARD_MODE_H

enum class KeyboardMode {
    QWERTY,
    NUMERIC,
    SYMBOL,
    EMOJI,
    SETTINGS
};

inline const char* modeName(KeyboardMode m) {
    switch (m) {
        case KeyboardMode::QWERTY:  return "QWERTY";
        case KeyboardMode::NUMERIC: return "NUMERIC";
        case KeyboardMode::SYMBOL:  return "SYMBOL";
        case KeyboardMode::EMOJI:   return "EMOJI";
        case KeyboardMode::SETTINGS:return "SETTINGS";
        default: return "UNKNOWN";
    }
}

#endif