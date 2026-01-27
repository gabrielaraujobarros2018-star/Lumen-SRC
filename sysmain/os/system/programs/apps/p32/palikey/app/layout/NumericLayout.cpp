#include "NumericLayout.h"

NumericLayout::NumericLayout(int w, int h)
    : KeyboardLayout(w, h) {}

void NumericLayout::addRow(const char* row, int y) {
    int count = 0;
    while (row[count]) count++;
    int kw = screenWidth / count;

    for (int i = 0; i < count; ++i) {
        keyRects.push_back({ i * kw, y, kw, rowHeight, row[i] });
    }
}

void NumericLayout::build() {
    keyRects.clear();
    addRow("123", 0 * rowHeight);
    addRow("456", 1 * rowHeight);
    addRow("789", 2 * rowHeight);
    addRow("0",   3 * rowHeight);
}