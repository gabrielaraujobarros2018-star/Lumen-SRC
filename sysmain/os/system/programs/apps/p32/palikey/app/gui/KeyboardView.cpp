#include "KeyboardView.h"

KeyboardView::KeyboardView(KeyboardLayout& layout)
    : layoutRef(layout) {}

void KeyboardView::build() {
    keys.clear();
    layoutRef.build();
    for (const auto& k : layoutRef.keys()) {
        keys.emplace_back(k);
    }
}

char KeyboardView::handleTouch(int x, int y) {
    for (const auto& key : keys) {
        if (key.hitTest(x, y)) {
            return key.symbol();
        }
    }
    return 0;
}

const std::vector<KeyWidget>& KeyboardView::widgets() const {
    return keys;
}