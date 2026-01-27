#include "SymbolLayout.h"

SymbolLayout::SymbolLayout(int w, int h)
    : KeyboardLayout(w, h) {}

void SymbolLayout::build() {
    keyRects.clear();
    const char* symbols = "!@#$%^&*()";
    int count = 10;
    int kw = screenWidth / count;

    for (int i = 0; i < count; ++i) {
        keyRects.push_back({ i * kw, 0, kw, rowHeight, symbols[i] });
    }

    const char* misc = "-_=+[]{}";
    count = 8;
    kw = screenWidth / count;

    for (int i = 0; i < count; ++i) {
        keyRects.push_back({ i * kw, rowHeight, kw, rowHeight, misc[i] });
    }
}