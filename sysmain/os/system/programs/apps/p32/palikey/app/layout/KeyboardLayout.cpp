#include "KeyboardLayout.h"

KeyboardLayout::KeyboardLayout(int width, int height)
    : screenWidth(width), screenHeight(height) {
    rowHeight = screenHeight / 4;
}

const std::vector<KeyRect>& KeyboardLayout::keys() const {
    return keyRects;
}