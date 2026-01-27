#include "QwertyLayout.h"

QwertyLayout::QwertyLayout(int width, int height)
    : KeyboardLayout(width, height) {}

void QwertyLayout::addRow(const char* row, int yOffset, int keyCount) {
    int keyWidth = screenWidth / keyCount;
    for (int i = 0; row[i]; ++i) {
        KeyRect k;
        k.x = i * keyWidth;
        k.y = yOffset;
        k.w = keyWidth;
        k.h = rowHeight;
        k.symbol = row[i];
        keyRects.push_back(k);
    }
}

void QwertyLayout::build() {
    keyRects.clear();
    addRow("QWERTYUIOP", 0 * rowHeight, 10);
    addRow("ASDFGHJKL", 1 * rowHeight, 9);
    addRow("ZXCVBNM",   2 * rowHeight, 7);

    KeyRect space;
    space.x = screenWidth / 4;
    space.y = 3 * rowHeight;
    space.w = screenWidth / 2;
    space.h = rowHeight;
    space.symbol = ' ';
    keyRects.push_back(space);
}