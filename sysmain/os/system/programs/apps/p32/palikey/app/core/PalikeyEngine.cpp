#include "PalikeyEngine.h"

PalikeyEngine::PalikeyEngine()
    : keySpacingPx(4), keyboardScale(1.0f) {}

void PalikeyEngine::setKeySpacing(int px) {
    if (px > 0) {
        keySpacingPx = px;
    }
}

void PalikeyEngine::setKeyboardScale(float scale) {
    if (scale >= 0.5f && scale <= 2.0f) {
        keyboardScale = scale;
    }
}

void PalikeyEngine::inputCharacter(char c) {
    buffer.push_back(c);
}

void PalikeyEngine::backspace() {
    if (!buffer.empty()) {
        buffer.pop_back();
    }
}

std::string PalikeyEngine::getBuffer() const {
    return std::string(buffer.begin(), buffer.end());
}